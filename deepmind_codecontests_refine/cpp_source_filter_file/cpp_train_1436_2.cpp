#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<string> s(n);
  vector<int> t(n);
  for(int i=0; i<n; ++i)cin>>s[i]>>t[i];
  string x; cin>>x;

  int e=0;
  for(int i=0; i<n; ++i)if(x==s[i]){e=i; break;}

  int ans=0;
  for(int i=e+1; i<n; ++i)sum+=t[i];
  cout<<sum<<endl;
}