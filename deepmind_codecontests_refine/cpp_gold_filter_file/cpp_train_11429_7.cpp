#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  if(s + t.back() == t)
    cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
