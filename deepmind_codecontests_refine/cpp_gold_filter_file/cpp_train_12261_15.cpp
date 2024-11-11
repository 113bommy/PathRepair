#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
  cin >> s;
  if(s=="SSS")
    cout<<0;
  else if(s=="RRR")
    cout<<3;
  else if(s=="SRR" || s=="RRS")
    cout<<2;
  else
    cout<<1;
}
