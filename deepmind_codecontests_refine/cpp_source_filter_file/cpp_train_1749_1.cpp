#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  string s;
  cin>>n>>s>>k;
  int count=1;
  for(int i=1;i<s.length();i++) if(s[i]!s[i-1])count++;
  count-=2*k;
  count=max(count,1);
    count=n-count;
  cout<<count<<endl;
 
}