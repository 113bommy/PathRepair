include<bits/stdc++.h>  
using namespace std;

int dp[3001][3001];
int a[3000], b[3000];
int N, T, S;

int rec(int idx, int time){
  if(idx == N || time == T) return(0);
  if(~dp[idx][time]) return(dp[idx][time]);
  int ret = max( rec( idx + 1, time), rec( idx, time + 1));
  if((time + b[idx] <= S || time >= S) && time + b[idx] <= T){
    ret = max( ret, rec( idx + 1, time + b[idx]) + a[idx]);
  }
  return(dp[idx][time] = ret);
}

int main(){
  fill_n( *dp, 3001 * 3001, -1);
  cin >> N >> T >> S;
  for(int i = 0; i < N; i++){
    cin >> a[i] >> b[i];
  }
  cout << rec(0,0) << endl;
}