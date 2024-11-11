#include <bits/stdc++.h>
using namespace std;
int main() {
  long long e = 0, o = 0, t, a[2][2] = {0};
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    t = s[i] - 'a', a[t][i & 1]++, o += a[t][i & 1], e += a[t][!(i & 1)];
  cout << e << " " << o;
}
