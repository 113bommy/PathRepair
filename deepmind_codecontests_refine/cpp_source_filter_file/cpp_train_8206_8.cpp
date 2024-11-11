#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],sum,cnt,ans=11111111111;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  for(int i=0;i<n-1;i++){
    cnt+=a[i];
    ans=min(ans,abs((sum-cnt)-cnt));
  }
  cout<<ans<<endl;
}
