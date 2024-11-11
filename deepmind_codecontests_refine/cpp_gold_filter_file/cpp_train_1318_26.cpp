#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, c;
  string s;
  cin >> s;
  c = count(s.begin(), s.end(), 'o');
  n = s.size();
  if (c == 0 || (n - c) % c == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
