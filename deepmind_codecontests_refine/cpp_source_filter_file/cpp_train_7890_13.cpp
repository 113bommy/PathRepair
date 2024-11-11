#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int i,n,k;
  string s;
  cin >> n >> s >> k+1;
for (i=0;i<n;i++)
  {if (s[i] != s[k]) s[i] = '*';}
 cout<<s<<endl;
}