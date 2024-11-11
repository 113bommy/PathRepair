#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

// dp[i]:i文字目を先頭とした場合の，Sの部分文字列でない最短の文字列の長さ
int nex[202020][26],dp[202020],ne[26];
// ta[i]:i文字目を先頭とした場合の，遷移先(2文字目)のアルファベット(0~25=a~z)
int ta[202020];

int main(){
  string S; cin>>S;
  int N=S.length();
  rep(i,26) ne[i]=nex[N+1][i]=N+1;
  for(int i=N;i>=0;i--){
    dp[i]=202020;
    // aから貪欲に遷移先を選ぶ
    rep(j,26){
      nex[i][j]=ne[j];
      int x=dp[ne[j]];
      if(x<dp[i]){
        dp[i]=x;
        ta[i]=j;
      }
    }
    dp[i]++;
    if(i) ne[S[i-1]-'a']=i;
  }

  string ans="";
  int cur=0;
  while(cur!=N+1){
    ans+=('a'+ta[cur]);
    cur=nex[cur][ta[cur]];
  }
  cout<<ans<<endl;
  return 0;
}
