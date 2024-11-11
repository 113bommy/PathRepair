#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Array 1400;
int dp[Array][Array];
int main(){
	int h, w, maxedge = 0;
	bool tail[Array][Array];
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++){
		for (int j = 0; j <w; j++){
			scanf("%d", &tail[i][j]);
			if (!tail[i][j]){
				dp[i][j] = 1;
				maxedge = 1;
			}
		}
	}
	for (int i = 1; i < h; i++){
		for (int j = 1; j < w; j++){
			if (!tail[i][j])
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			maxedge = max(maxedge, dp[i][j]);
		}
	}
	printf("%d\n", maxedge * maxedge);
	return 0;
}