#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ( )
{
 ll a,b,c;
  cin>>a>>b>>c;
  cout<<min(min(a+b,a+c),b+c)<<endl;
}
