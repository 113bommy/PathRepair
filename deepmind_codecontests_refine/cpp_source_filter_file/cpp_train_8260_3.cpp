#include <bits/stdc++.h>
using namespace std;
constexpr auto PI = 3.14159265358979323846L;
constexpr auto oo = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
int main() {
  int n;
  cin >> n;
  if (n == 1) cout << 1 << endl, exit(0);
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int c[2000051] = {0};
  set<int> s, t;
  for (int i = 0; i < n; i++) {
    t.clear();
    for (auto j : s) t.insert(j | a[i]);
    t.insert(a[i]);
    s.swap(t);
    for (auto j : s) c[j]++;
  }
  int d = 0;
  for (int i = 0; i < 20; i++) {
    if (c[i] > 0) d++;
  }
  cout << d << endl;
}
