#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  s = string(n, 'a');
  for (int i = 0; i < n; ++i) s[i] += (i % 4) / 2;
  cout << s;
  return 0;
}
