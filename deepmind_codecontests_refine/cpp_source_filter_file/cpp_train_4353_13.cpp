#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i=0;
  cin>>n;
  vector< pair< pair<string,int>,int > > v;
  string s;
  int p;
  while(n--)
  {
    i++;
    cin>>s>>p;
    v.push_back({{s,-p},i});
  }
  sort(v.begin(),v.end());
  for(auto q:v) cout<<v.second<<endl;
  return 0;
}