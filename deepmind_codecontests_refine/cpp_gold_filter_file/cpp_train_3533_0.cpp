#include<bits/stdc++.h>
using namespace std;
   
int n,m,b[510][510];
int pc[1<<24],dp[2][1<<24],bits[510];
   
void compute() {
  int maxi = 0;
  if( n <= m ) {
    for(int i=0;i<(1<<n);i++) {
      if( maxi >= pc[i] ) continue;
      bool ok = true;
      for(int x=0;x<m;x++) {
    int cnt = 0;
    for(int y=0;y<n;y++) if( ( (i>>y) & 1 ) && b[y][x] ) ++cnt;
    if( cnt & 1 ) {
      ok = false;
      break;
    }
      }
      if( ok ) maxi = max(maxi,pc[i]);
    }
  } else { // n > m
   int list[501];
      fill(list,list+n,0);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(b[i][j]){
            list[i]=list[i]|(1<<j);
          }
        }
      }
      for(int i=0;i<2;i++)for(int j=0;j<(1<<m);j++)dp[i][j]=-1;
      dp[0][0]=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<(1<<m);j++)dp[(i+1)&1][j]=-1;
        for(int j=0;j<(1<<m);j++){
          if(dp[i&1][j]==-1)continue;
          dp[(i+1)&1][j^list[i]]=max(dp[(i+1)&1][j^list[i]],dp[i&1][j]+1);
          dp[(i+1)&1][j]=max(dp[(i+1)&1][j],dp[i&1][j]);
        }
      }
      if(dp[n&1][0]!=-1)maxi=dp[n&1][0];
  }
  cout << maxi << endl;
}
   
int main() {
  for(int i=0;i<(1<<23);i++) pc[i] = __builtin_popcount(i);
  while( cin >> n >> m, n|m ) {
    for(int i=0;i<n;i++) {
      string s;
      cin >> s;
      for(int j=0;j<m;j++) b[i][j] = ( s[j] == '1' );
    }
    compute();
  }
  return 0;
}
