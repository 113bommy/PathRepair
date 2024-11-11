#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a=0,b=0;
  cin>>n;
  vector<int> c(n);
  for(int i=0;i<n;i++) cin>>c[i];
  sort(c.begin(),c.end(),greater<int>());
  for(int i=0;i<n;i++){
    if(i%2==0)a+=c[i];
    else b+=c[i];
  }
  cout<<a-b;
}