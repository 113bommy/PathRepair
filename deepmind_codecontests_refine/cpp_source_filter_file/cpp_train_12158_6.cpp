#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  set<strings> s;
  string p;
  for(int i=0;i<n;i++)
  {
    cin>>p;
    s.insert(p);
  }
  cout<<s.size();
}