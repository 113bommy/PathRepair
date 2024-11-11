#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a[200001],b[200001];
  long long ans=0;
  set<int> s;
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],b[a[i]]=i;
  s.insert(0);
  s.insert(n+1);
  for(int i=1;i<=n;i++){
    set<int>::iterator it=s.lower_bound(b[i]);
    long long right = (*it) -b[i];
    it--;
    long long left = b[i] - (*it);
    ans+=right*left*i;
    s.insert(b[i]);
  }
  cout<<ans<<endl;
  return 0;
}
