#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll fc[200010];
ll ifc[200010];

ll add(ll x, ll y){return (x+y)%MOD;}
ll mlt(ll x, ll y){return (x*y)%MOD;}
ll power(ll x, ll n){
  ll ans=1;
  while(n>0){
    if(n%2!=0)ans=mlt(ans, x);
    x=mlt(x,x);n/=2;
  }
  return ans;
}

ll inv(ll x){return power(x, MOD-2);}

void fct(){
  fc[0]=1;
  for (int i=0;i<200009;++i){fc[i+1]=mlt(fc[i], i+1);}
}

void ifct(){
  ifc[200009]=inv(fc[200009]);
  for (int i=200009;i>=1;--i){ifc[i-1]=mlt(ifc[i], i);}
}

ll comb(int n, int k){return mlt(fc[n], mlt(ifc[k], ifc[n-k]));}

int main(){
  int N, A, B, C, D;cin>>N>>A>>B>>C>>D;

  fct();ifct();
  ll dp[1010][1010]={};dp[N][A-1]=1;

  for (int j=A;j<=B;++j){
    for (int i=N;i>=0;--i){
      dp[i][j]=dp[i][j-1];

      ll factor=1;
      for (int k=0;k++<C-1;){
        factor=mlt(factor, comb(i+j*k, j));
      }

      for (int k=C;k<=D;++k){
        if(i+j*k>N) break;
        factor=mlt(factor, comb(i+j*k,j));
        dp[i][j]=add(dp[i][j], mlt(dp[i+j*k][j-1],mlt(factor, ifc[k])));
      }
    }
  }

  cout << dp[0][B] << endl;
  return 0;
}