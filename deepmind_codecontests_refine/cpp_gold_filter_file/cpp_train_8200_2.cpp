#include<iostream>
#include<set>
using namespace::std;

int main(){
  int n;
  cin>>n;
  set<int> s;
  for(int i=0,t;i<n;i++)
    cin>>t,s.insert(t);
  if(s.size()==n)
    cout<<"YES\n";
  else cout<<"NO\n";
}