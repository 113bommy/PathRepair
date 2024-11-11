#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, int r = 2147483647) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
    a %= r;
    res %= r;
  }
  return res;
}
void B() {
  int t;
  for (cin >> (t); (t)--;) {
    int n;
    cin >> n;
    int zr = 0, on = 0, nch = 0;
    multiset<int> sz;
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      sz.insert(s.size());
      for (char j : s)
        if (j == '1')
          on++;
        else
          zr++;
    }
    nch = zr % 2 + on % 2;
    int out = 0, ob = zr + on - nch;
    for (int i : sz) {
      if (i % 2) {
        if (ob + nch < i) break;
        if (nch) {
          nch--;
          ob -= i - 1;
        } else {
          nch++;
          ob -= i - 1;
        }
      } else {
        if (ob < i) break;
        ob -= i;
      }
      out++;
    }
    cout << out << '\n';
  }
}
int main() {
  if (true) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
  }
  B();
  return 0;
}
