#include <bits/stdc++.h>
using namespace std;

  long long a,b,c;
int main()
{
  cin>>a>>b>>c;
  cout<<min(a*b*(c&1),min(a*c*(b&1),b*c*(a&1));
  exit(0);
}

