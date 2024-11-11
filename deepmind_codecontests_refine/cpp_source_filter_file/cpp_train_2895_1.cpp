#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;cin >> s;
  int n = s.length(),cnt=0;
  for(int i=0;i<n;i++)if(s[i]-'0' == i%2)cnt++;
  cout << min(count,n-count);
  return 0;
}