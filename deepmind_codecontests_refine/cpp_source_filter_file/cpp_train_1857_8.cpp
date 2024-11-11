#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int cnt=0;
  for(int j=0;j<n;j++){
    if(i%2==0) cnt+=a[j];
    else cnt-=a[j];
  }
  cout<<cnt;
}