#include <bits/stdc++.h>
using namespace std;
string s;
int n, f[1 << 20];
int main() {
  cin >> s;
  int n = s.size() - 1;
  bitset<20> m;
  for (int i = 0; i < n; i++) {
    m.reset();
    for (int j = i; j <= i + 25 && j <= n; j++)
      if (m[s[j] - 'a'] == 1)
        break;
      else {
        m[s[j] - 'a'] = 1;
        f[m.to_ullong()] = j - i + 1;
      }
  }
  for (int i = 0; i < (1 << 20); i++)
    for (int j = 0; j <= 19; j++)
      if (i & (1 << j)) f[i] = max(f[i], f[i ^ (1 << j)]);
  int kq = 0;
  for (int i = 0; i < (1 << 20); i++)
    kq = max(kq, f[i] + f[i ^ ((1 << 20) - 1)]);
  cout << kq;
  return 0;
}
