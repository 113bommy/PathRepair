#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
#define fin {cout<<""<<endl;return 0;}
//template

//main
signed main(){
  int N;cin>>N;
  std::vector<int> a(N),b(N);
  for(int i=0;i<N;i++)cin>>a[i]>>b[i];
  for(int i=0;i<N;i++){
    int K=a[i]*b[i];
    int l=0,h=MOD;
    while(h-l>1){
      int m=(h+l)/2;
      if(m*m<K)l=m;
      else h=m;
    }
    int ans=2*l;
    if(l*(l+1)>=K)ans--;
    if(l>=min(a[i],b[i]))ans--;
    cout<<ans<<endl;
  }
}
