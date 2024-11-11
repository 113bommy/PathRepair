#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
int n;
struct uzi{
  int a,b,i;
  bool operator <(const uzi &t)const{
    return a<t.a;
  }
}p[N];
LL L[N],f[N];
const LL mod=998244353;
int t[N];
void add(int p,int d){
  for(;p<N;p+=p&-p)t[p]=max(t[p],d);
}
int ge(int p,int d){
  int res=0;
  for(;p;p-=p&-p)res=max(res,t[p]);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b,p[i].i=i;
  sort(p+1,p+1+n);
  auto get=[&](int x){
    int l=1,r=n,ans=1;
    while(l<=r){
      int mid=l+r>>1;
      if(p[mid].a<=x)ans=mid,l=mid+1;
      else r=mid-1;
    }
    return ans;
  };
  for(int i=n;i>=1;i--){
    L[i]=i;
    int x=get(p[i].a+p[i].b-1);
    L[i]=max(L[i],ge(x,1));
    add(i,L[i]);
  }
//  for(int i=1;i<=n;i++){
//    cout<<i<<' '<<L[i]<<endl;
//  }
  f[1]=1;
  for(int i=1;i<=n;i++){
    f[i+1]+=f[i];//不开
    f[L[i]+1]+=f[i];//开
    f[i+1]%=mod;
    f[L[i]+1]%=mod;
  }
  cout<<f[n+1]<<endl;
  return 0;
}