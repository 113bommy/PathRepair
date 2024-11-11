#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int n, m;
set<long long> s;
int count(int x) {
  if (x == 0) return 1;
  int c = 0;
  while (x > 0) {
    x /= 7;
    c++;
  }
  return c;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int pn = count(n - 1);
  int pm = count(m - 1);
  if (pn + pm > 7)
    cout << 0 << endl;
  else {
    int a[10];
    for (int i = 0; i < 7; i++) a[i] = i;
    do {
      long long tn = 0;
      for (int i = 0; i < pn; i++) tn = tn * 7 + a[i];
      long long tm = 0;
      for (int i = 0; i < pm; i++) tm = tm * 7 + a[pn + i];
      if (tn < n && tm < m) {
        tn = tn * m + tm;
        s.insert(tn);
      }
    } while (next_permutation(a, a + 7));
  }
  cout << s.size() << endl;
  return 0;
}
