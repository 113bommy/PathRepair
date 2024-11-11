#include <iostream>
#include <cmath>
using namespace std;
int a[100][100],b[100][100];
bool dp[81][81][15000];
int main(){
	int i,j,k,h,w;
	cin >> h >> w;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cin >> a[i][j];
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cin >>b[i][j];
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			for(k=0;k<15000;k++){
				dp[i][j][k] = false;
			}
		}
	}
	dp[0][0][abs(a[0][0] - b[0][0]] = true;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			for(k=0;k<15000;k++){
				if(!dp[i][j][k]) continue;
				dp[i + 1][j][abs(k + a[i + 1][j] - b[i + 1][j])] = true;
				dp[i + 1][j][abs(k - a[i + 1][j] + b[i + 1][j])] = true;
				dp[i][j + 1][abs(k + a[i][j + 1] - b[i][j + 1])] = true;
				dp[i][j + 1][abs(k - a[i][j + 1] + b[i][j + 1])] = true;
			}
		}
	}
	for(i=0;i<=6400;i++){
		if(dp[h - 1][w - 1][i]){
			cout << i << endl;
			return 0;
		}
	}
}