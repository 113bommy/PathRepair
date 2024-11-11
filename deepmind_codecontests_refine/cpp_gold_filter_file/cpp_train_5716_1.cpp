#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
vector<int>G[10];
vector<int>Gsum[10];
int dp[10][2000];
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++){
		int A, B;
		scanf("%d%d", &A, &B);
		G[B - 1].push_back(A);
	}
	for (int i = 0; i < 10; i++){
		sort(G[i].begin(), G[i].end());
		reverse(G[i].begin(), G[i].end());
	}
	for (int i = 0; i < 10; i++){
		Gsum[i].push_back(0);
		
		for (int j = 0; j < G[i].size(); j++){
			int sum = 0;
			for (int k = 0; k <= j; k++){
				sum += G[i][k];
			}
			sum += (j + 1)*j;
			if (G[i].size()>0)Gsum[i].push_back(sum);
		}
	}
	for (int j = 0; j <= min(K, (int)Gsum[0].size() - 1); j++)dp[0][j] = Gsum[0][j];
	for (int i = 1; i < 10; i++){
		for (int j = 0; j <= K; j++){
			int dpij = 0;
			for (int k = 0; k <= min(j, (int)Gsum[i].size()-1);k++){
				dpij = max(dpij,dp[i - 1][j - k] + Gsum[i][k]);
			}
			dp[i][j] = dpij;
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= K; i++)ans = max(ans, dp[9][i]);
	printf("%d\n", ans);
}