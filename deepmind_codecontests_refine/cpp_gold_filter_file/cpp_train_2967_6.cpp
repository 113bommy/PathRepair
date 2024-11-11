#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int a[maxn], prime[maxn + 1], pal[maxn];
bool f(int n) {
  string s = "";
  while (n > 0) {
    s += (n % 10 + '0');
    n /= 10;
  }
  for (int i = 0; i <= s.size() / 2; i++)
    if (s[i] != s[s.size() - i - 1]) return false;
  return true;
}
int main() {
  int idx, m, n;
  cin >> m >> n;
  for (int i = 1; i < maxn; i++) a[i] = 1;
  for (int i = 2; i < maxn; i++) {
    for (int j = 2; (i * j) < maxn; j++) {
      idx = (i * j);
      a[idx] = 0;
    }
  }
  pal[1] = 1;
  for (int i = 2; i <= maxn; i++) {
    prime[i] = prime[i - 1] + a[i];
    pal[i] = pal[i - 1] + f(i);
  }
  for (int i = maxn - 1; i >= 1; i--) {
    if (m * pal[i] >= n * prime[i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "Palindromic tree is better than splay tree" << endl;
  return 0;
}
