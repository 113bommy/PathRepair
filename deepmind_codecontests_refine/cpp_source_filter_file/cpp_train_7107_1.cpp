#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<long, long>;
struct fast_ios {
  fast_ios() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  }
} fast_ios_;
int solve() {
  int n;
  cin >> n;
  vector<int> dv, pri;
  dv.push_back(1);
  int nn = n;
  for (int i = 2; i * i <= nn; ++i) {
    if (n % i == 0) {
      pri.push_back(i);
      int v = 1;
      int sz = dv.size();
      while (n % i == 0) {
        n /= i;
        v *= i;
        for (int i = 0; i < sz; ++i) {
          dv.push_back(dv[i] * v);
        }
      }
    }
  }
  if (n != 1) {
    pri.push_back(n);
    int sz = dv.size();
    for (int i = 0; i < sz; ++i) {
      dv.push_back(dv[i] * n);
    }
  }
  vector<bool> vis(dv.size());
  if (pri.size() == 1) {
    for (int i = 1; i < dv.size(); ++i) printf("%d ", dv[i]);
    return puts("\n0");
  }
  if (pri.size() == 2) {
    if (dv.size() == 4) {
      for (int i = 1; i < dv.size(); ++i) printf("%d ", dv[i]);
      return puts("\n1");
    }
    int a = -1, b = -1;
    for (int i = 0; i < dv.size(); ++i) {
      if (dv[i] % pri[0] == 0 && dv[i] % pri[1] == 0) {
        if (a == -1)
          a = dv[i];
        else
          b = dv[i];
      }
    }
    set<int> se;
    se.insert(pri[0]);
    se.insert(pri[1]);
    se.insert(a);
    se.insert(b);
    printf("%d ", pri[0]);
    for (int i = 1; i < dv.size(); ++i) {
      if (se.find(dv[i]) == se.end() && dv[i] % pri[0] == 0)
        printf("%d ", dv[i]), se.insert(dv[i]);
    }
    printf("%d %d ", a, pri[1]);
    for (int i = 1; i < dv.size(); ++i) {
      if (se.find(dv[i]) == se.end() && dv[i] % pri[1] == 0)
        printf("%d ", dv[i]);
    }
    return printf("%d\n0", b);
  }
  for (int i = 0; i < pri.size(); ++i) {
    int a = pri[i];
    int b = pri[(i + 1) % pri.size()];
    int c = pri[(i - 1 + pri.size()) % pri.size()];
    printf("%d ", a);
    for (int j = 0; j < dv.size(); ++j) {
      if (!vis[j] && dv[j] % a == 0) {
        vis[j] = true;
        if (dv[j] != a && dv[j] != a * b && dv[j] != a * c)
          printf("%d ", dv[j]);
      }
    }
    printf("%d ", a * b);
  }
  puts("\n0");
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
