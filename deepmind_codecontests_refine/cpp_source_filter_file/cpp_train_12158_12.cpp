#include<bits/stdc++.h>
using namespace std;
int main()
{
  map<string,int>m;
  int n;cin>>n;
  while(n--){string a;cin>>a;m[a]++;}
  cout<<m.size()<<<endl;
}
