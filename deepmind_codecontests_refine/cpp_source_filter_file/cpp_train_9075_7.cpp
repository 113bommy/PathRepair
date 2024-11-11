#include <bits/stdc++.h>
using namespace std;
long long int abs1(long long int a) { return a > 0 ? a : -1 * a; }
bool cmp(pair<int, int> a, pair<int, int> b) { return (a.first > b.first); }
int main() {
  string s;
  cin >> s;
  int a, b = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '4')
      a++;
    else if (s[i] == '7')
      b++;
  }
  if (a == 0 && b == 0) {
    cout << -1;
    return 0;
  }
  if (a >= b)
    cout << 4;
  else
    cout << 7;
}
