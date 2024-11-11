#include<iostream>
#include<algorithm>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
namespace fio {
	streambuf* in = cin.rdbuf();
	char bb[1000000], * s = bb, * t = bb;
#define gc() (s==t&&(t=(s=bb)+in->sgetn(bb,1000000),s==t)?EOF:*s++)
	inline int read() {
		int x = 0;
		char ch = gc();
		while (ch < 48)ch = gc();
		while (ch >= 48)x = x * 10 + ch - 48, ch = gc();
		return x;
	}
}using fio::read;
int n, m;
int arr[15][15];
int dp[305][305];
int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)for (int u = 1; u <= m; u++)arr[i][u] = read();
	for (int i = 0; i <= 100; i++)for (int u = 0; u <= 100; u++)for (int x = 1; x <= n; x++)for (int y = 1; y <= m; y++)dp[i][u] = max(dp[i][u], arr[x][y] - i * x - u * y);
	for (int x = 0; x <= n; x++)for (int y = 0, now = 0x7fffffff; y <= m; now = 0x7fffffff, y++) {
		for (int i = 0; i <= 100; i++)for (int u = 0; u <= 100; u++)
			now = min(now, dp[i][u] + i * x + u * y);
		if (now != arr[x][y])cout << "Impossible", exit(0);
	}
	puts("Possible"), puts("202 10401");
	for (int i = 1; i <= 201; i++)if (i != 101)cout << i << ' ' << i + 1 << ' ' << (i <= 100 ? 'X' : 'Y') << endl;
	for (int i = 0; i <= 100; i++)for (int u = 0; u <= 100; u++)printf("%d %d %d\n", i + 1, 202 - u, dp[i][u]);
	cout << 1 << ' ' << 202;
}