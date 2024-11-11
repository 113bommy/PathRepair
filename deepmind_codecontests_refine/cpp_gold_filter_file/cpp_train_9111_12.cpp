#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
vector<int> primes;
vector<bool> iscomposite;
int precalc(int n) {
  primes = vector<int>();
  iscomposite = vector<bool>(n + 1, false);
  for (int i = 2; i <= n; i++) {
    if (!iscomposite[i]) {
      primes.push_back(i);
    }
    for (int j = 0; primes[j] * i < n; j++) {
      iscomposite[primes[j] * i] = true;
      if (i % primes[j] == 0) {
        break;
      }
    }
  }
  return 0;
}
int a[1000006];
int main() {
  precalc(2000001);
  int n;
  cin >> n;
  pair<int, int> ans1 = {0, 0};
  pair<int, int> ans2 = {0, 0};
  vector<int> ansa;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) cnt++;
  }
  pair<int, int> sw = {0, 0};
  bool fl = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (iscomposite[a[i] + a[j]] == false) {
        fl = true;
        ans1 = {a[i], a[j]};
        if ((ans2 == sw || (a[i] == 1) + (a[j] == 1) <
                               (ans2.first == 1) + (ans2.second == 1)) &&
            !iscomposite[a[i] + 1] && !iscomposite[a[j] + 1]) {
          ans2 = {a[i], a[j]};
        }
      }
    }
  }
  if (!fl) {
    cout << "1\n" << a[0];
    return 0;
  }
  ansa.push_back(ans1.first);
  ansa.push_back(ans1.second);
  if (cnt > 0 && ans2 != sw) {
    ansa.pop_back();
    ansa.pop_back();
    int rem = (ans2.first == 1) + (ans2.second == 1);
    cnt -= rem;
    while (cnt--) ansa.push_back(1);
    ansa.push_back(ans2.first);
    ansa.push_back(ans2.second);
  }
  cout << ansa.size() << "\n";
  for (auto i : ansa) cout << i << " ";
}
