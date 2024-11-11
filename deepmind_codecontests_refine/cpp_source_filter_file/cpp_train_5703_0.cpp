#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i,n)for(i=0;i<n;i++)
void cm(ll &a,ll b){if(a>b)a=b;}
int main(void){ll n,s,k,v,i;cin>>n;vl x(n),y(n),p(n),a(n+1,1LL<<60);vector<vl>X(n),Y(n);rep(i,n)cin>>x[i]>>y[i]>>p[i];rep(i,n){X[i]=vl(1<<n,abs(x[i])),Y[i]=vl(1<<n,abs(y[i]));rep(b,1<<n)rep(j,n)if(b&1<<j)cm(X[i][b],abs(x[i]-x[j])),cm(Y[i][b],abs(y[i]-y[j]));}rep(b,1<<n){s=b;do{k=__builtin_popcountl(b),v=0;rep(i,n)v+=p[i]*min(X[i][s],Y[i][b&~s]);cm(a[k],v),s=(s-1)&b;}while(s!=b);}rep(i,n+1)cout<<a[i]<<endl;return 0;}