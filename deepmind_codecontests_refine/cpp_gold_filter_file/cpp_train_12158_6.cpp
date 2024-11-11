#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i;
  cin>>n;
  set<string>s;
  for(i=0;i<n;i++){
    string s1;
    cin>>s1;
    s.insert(s1);
  }
  cout<<s.size();

  return 0;
}