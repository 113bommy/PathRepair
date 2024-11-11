#include<bits/stdc++.h>
using namespace std;
int main(){
   int k;
  string s;
  cin>>k>>s;
  int l=s.size();
  if(l<=k) cout<<s<<endl;
  esle cout<<s.substr(0,k)<<"..."<<endl;
  return 0;
}