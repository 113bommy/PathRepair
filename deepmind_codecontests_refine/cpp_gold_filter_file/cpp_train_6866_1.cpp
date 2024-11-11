#include<bits/stdc++.h>
using namespace std;
/* 変数名を被らせない
   デバッグコードを取り除く */
#define ANSWER(x) cout<<x<<endl
#define debug(x) cout<<#x<<": "<<x
const int MAX_INT = 1000000;
string name;
int C[301],V[301],D[301],L[301];
int dp[301][301][3];
int N,M;
int solve(int a,int b,int s);
int main(){
  while(cin >> N >> M){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
      cin.ignore();
      getline(cin,name);
      cin >> C[i] >> V[i] >> D[i] >> L[i];
    }
    cout << max(solve(0,M,0),max(solve(0,M,1),solve(0,M,2))) << endl;
  }
}
int solve(int a,int b,int s){
  if(dp[a][b][s] != -1)return dp[a][b][s];
  else {if(a==N)return 0;
    else if(b < C[a])return dp[a][b][s] = solve(a+1,b,s);
    else {
      if(s == 0)return dp[a][b][s] = max(solve(a+1,b-C[a],s)+V[a],max(solve(a,b-C[a],s)+V[a],solve(a+1,b,s)));
      else if(s == 1)return dp[a][b][s] = max(solve(a+1,b-C[a],s)+D[a],max(solve(a,b-C[a],s)+D[a],solve(a+1,b,s)));
      else return dp[a][b][s] = max(solve(a+1,b-C[a],s)+L[a],max(solve(a,b-C[a],s)+L[a],solve(a+1,b,s)));
    }
  }
}