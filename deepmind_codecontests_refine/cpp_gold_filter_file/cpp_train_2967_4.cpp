#include <bits/stdc++.h>
using namespace std;
bool pr[10001000];
bool pal(long long x) {
  vector<int> p;
  while (x > 0) {
    p.push_back(x % 10);
    x /= 10;
  }
  for (int i = 0; i < p.size() / 2; i++) {
    if (p[i] != p[p.size() - i - 1]) return 0;
  }
  return 1;
}
int main() {
  int mx = 5e6;
  pr[0] = pr[1] = 1;
  for (int i = 2; i <= mx; i++) {
    if (!pr[i]) {
      for (int j = 2 * i; j <= mx; j += i) {
        pr[j] = 1;
      }
    }
  }
  long long p1, q1;
  cin >> p1 >> q1;
  long long p = 0, r = 0;
  long long res = -1;
  for (int i = 1; i <= mx; i++) {
    p += pal(i);
    r += !pr[i];
    if (r * q1 <= p1 * p) {
      res = i;
    }
  }
  if (res == -1) {
    cout << "Palindromic tree is better than splay tree\n";
  } else
    cout << res << endl;
  return 0;
}
