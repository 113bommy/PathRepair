#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll a,b,c;
  cin>>a>>b>>c;
  if(c-a-b>0 && (4*a*b<(c-a-b)*(c-a-b)) )
    cout<<"Yes";
  else 
    cout<<"No";
}