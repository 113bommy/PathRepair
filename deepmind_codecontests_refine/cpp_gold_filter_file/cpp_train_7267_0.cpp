#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

double dp[310][310][310];
int n;
 
double find(int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	if (a == 0 && b == 0 && c == 0) return 0;
	if (dp[a][b][c] == 0) {
		dp[a][b][c] = n + a*find(a - 1, b, c) + b*find(a + 1, b - 1, c) + c*find(a, b + 1, c - 1);
		dp[a][b][c] /= a + b + c;
	}
	return dp[a][b][c];
}
 
int main() {
  	cin >> n;
  	int cnt[5] = {};
  	cout << setprecision(10) << fixed;
	rep(i,n){
    	int a;
    	cin >> a;
    	cnt[a]++;
  	}
 
  cout << find(cnt[1], cnt[2], cnt[3]) << '\n';
 
  return 0;
}