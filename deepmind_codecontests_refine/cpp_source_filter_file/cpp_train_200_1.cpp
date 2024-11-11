// OBツ嘉ッツ嘉債宿2011 Day3 F : Beautiful Currency

#include <iostream>
#include <cstdio>
#include <stdlib>

using namespace std;

int main(){
	int N;
	int a[20];
	while(cin >> N){
		for(int i=0;i<N;i++) cin >> a[i];
		static double dp[2][200001];
		for(int i=1;i<=200000;i++){
			dp[0][i] = abs(a[0]-i)/(double)a[0];
		}
		int cur = 0, next = 1;
		for(int i=1;i<N;i++){
			for(int j=0;j<=200000;j++) dp[next][j] = 1e12;
			for(int j=1;j<=200000;j++)
				for(int k=j;k<=200000;k+=j)
					dp[next][k] = min(dp[next][k], max(dp[cur][j], abs(a[i]-k)/(double)a[i]));
			swap(cur, next);
		}
		double res = 1e12;
		for(int i=1;i<=200000;i++) res = min(res, dp[cur][i]);
		printf("%.10lf\n", res);
	}
}