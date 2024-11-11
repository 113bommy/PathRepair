#include <bits/stdc++.h>
using namespace std;
const int m=1000005;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  vector<int> cnt(m);
  for(auto x:a){
    if(cnt[x]!=0){
      cnt[x]=2;
    }else{
      for(int i=x;i<m;i+=x)cnt[i]++;
    }
  }
  int ans=0;
  for(auto x:a){
    if(cnt[x]==1)ans++;
  }
  cout<<ans<<endl;
  return 0;
}
  
