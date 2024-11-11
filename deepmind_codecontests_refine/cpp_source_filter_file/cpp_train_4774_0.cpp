#include <iostream>

using namespace std;

int n, a, b, ans = 1e9;
int A[100], B[100], C[100];
int dp[555][555];

int main()
{
	cin >> n >> a >> b;
	double d = a/b;
	
	for(int i=1; i <= n; i++)
		cin >> A[i] >> B[i] >> C[i];
	for(int i=0; i <= 400; i++)
		for(int h=0; h <= 400; h++)
			dp[i][h] = 1e9;
	
	dp[0][0] = 0;
	for(int i=1; i <= n; i++)
		for(int h=400; h >= 0; h--)
			for(int j=400; j >= 0; j--)
				if(dp[h][j] != 1e9) {
					int x = h+A[i];
					int y = j+B[i];
					
					if(dp[x][y] > dp[h][j]+C[i])
						dp[x][y] = dp[h][j]+C[i];
				}
	
	for(int i=1; i <= 400; i++)
		if (x*i <= 400 && y*i <= 400)
		ans = min(ans, cp[x*i][y*i]);

	if(ans == 1e9)
		ans = -1;
	cout << ans;
}