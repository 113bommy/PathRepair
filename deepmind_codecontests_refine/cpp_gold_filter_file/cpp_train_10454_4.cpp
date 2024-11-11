#include <bits/stdc++.h>
using namespace std;
int k, x, n, m;
string make(int n, int c, bool s, bool e) {
  string ret = "";
  ret.resize(n);
  int l = 0, r = n;
  if (s) ret[l++] = 'C';
  if (e) ret[--r] = 'A';
  while (c--) ret[l++] = 'A', ret[l++] = 'C';
  while (l < r) ret[l++] = 'X';
  return ret;
}
long long count(int k, long long ac1, long long ac2, bool s1, bool e1, bool s2,
                bool e2) {
  if (k == 2) return ac2;
  return count(k - 1, ac2, ac1 + ac2 + (e1 * s2), s2, e2, s1, e2);
}
void isAnswerExist(long long ac1, long long ac2, bool s1, bool e1, bool s2,
                   bool e2) {
  if (2 * ac1 + s1 + e1 > n) return;
  if (2 * ac2 + s2 + e2 > m) return;
  if (count(k, ac1, ac2, s1, e1, s2, e2) == x) {
    cout << make(n, ac1, s1, e1) << "\n" << make(m, ac2, s2, e2);
    exit(0);
  }
}
int main() {
  cin >> k >> x >> n >> m;
  for (int i = 0; i + i <= n; i++) {
    for (int j = 0; j + j <= m; j++) {
      for (int st = 0; st < 16; st++) {
        isAnswerExist(i, j, st & 1, (st >> 1) & 1, (st >> 2) & 1,
                      (st >> 3) & 1);
      }
    }
  }
  cout << "Happy new year!";
  return 0;
}
