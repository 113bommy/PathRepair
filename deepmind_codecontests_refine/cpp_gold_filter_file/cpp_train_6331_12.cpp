#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a=0;cin>>n;
  vector<int>p(n);
  for(int i=0;i<n;i++){
    cin>>p.at(i);
    a+=p.at(i);
  }
  sort(p.begin(),p.end());
  a-=p.at(n-1)/2;
  cout<<a<<endl;
}
  
