#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n,q;
  cin>>n;
  vector<int>v(n);
  r(i,n)cin>>v[i];
  cin>>q;
  while(q--){
    int a;
    cin>>a;
    if(*lower_bound(v.begin(),v.end(),a)==a)cout<<1<<endl;
    else cout<<0<<endl;
  }
}
