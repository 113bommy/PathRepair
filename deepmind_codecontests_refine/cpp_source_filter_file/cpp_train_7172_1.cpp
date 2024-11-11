#include<cstdio>
#include<iostream>
#define INF 10000000
using namespace std;
int dp[2][100000][2]={{{0}}};

int main(){

    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 100000;j++){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    int N;
    cin>>N;
    int v[100000]={0};
    for(int i = 0; i < N - 1;i++){
        cin>>v[i+1];
    }
    v[N-1] = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N+1;j++){
            for(int k = 0;k < 2;k++){
                dp[(i+1)%2][j][k] = INF;
            }
        }
        dp[(i+1)%2][0][1] = v[i];
        for(int j = 0;j < N/2;j++){
            if(dp[i%2][j][1]!=INF){
                dp[(i+1)%2][j+1][0] = min(dp[(i+1)%2][j+1][0],dp[i%2][j][1]+v[i]);
                dp[(i+1)%2][j][1] = min(dp[(i+1)%2][j][1],dp[i%2][j][1]-v[i-1]+v[i]);
            }
            if(dp[i%2][j][0]!=INF){
                dp[(i+1)%2][j+1][0] = min(dp[(i+1)%2][j+1][0],dp[i%2][j][0]-v[i-1]+v[i]);
                dp[(i+1)%2][j][1] = min(dp[(i+1)%2][j][1],dp[i%2][j][0]+v[i]);
            }
        }
    cout<<dp[0][N/2-1][0]<<endl;
    return 0;
}