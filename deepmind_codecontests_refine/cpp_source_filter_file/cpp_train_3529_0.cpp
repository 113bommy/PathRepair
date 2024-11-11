#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)(n);i++)
#define FORR(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define pb(a) push_back(a)
#define ZERO(a) memset(a,0,sizeof(a))
#define int long long
#define INF 1<<29
#define MAX 100000
using namespace std;

int n,m,p[MAX],a[MAX],b[MAX],c[MAX],sum[MAX];

void solve(){
 cin>>n>>m;
 ZERO(sum);
 FOR(i,m) cin>>p[i];
 FOR(i,n-1) cin>>a[i]>>b[i]>>c[i];
 FOR(i,m) p[i]--;
 FOR(i,m-1){
  sum[max(p[i],p[i+1])]--;
  sum[min(p[i],p[i+1])]++;
 }
 int ans=0;
 FOR(i,n-1){
  sum[i+1]+=sum[i];
  ans+=min(sum[i]*a[i],sum[i]*b[i]+c[i]);
 }
 cout<<ans<<endl;
}

int main(){
 solve();
 return 0;
}