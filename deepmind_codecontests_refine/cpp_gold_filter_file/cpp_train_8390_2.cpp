#include <bits/stdc++.h>
using namespace std;
unsigned long long K;
unsigned long long mult(unsigned long long x, unsigned long long y) {
  if (y == 0) return 0;
  unsigned long long res = 2 * mult(x, y / 2);
  if (y & 1) {
    res += x;
  }
  return min(res, K);
}
unsigned long long add(unsigned long long a, unsigned long long b) {
  return a + b <= K ? a + b : K;
}
vector<vector<unsigned long long>> operator*(
    const vector<vector<unsigned long long>> &a,
    const vector<vector<unsigned long long>> &b) {
  for (int i = 1; i < a.size(); i++) {
    assert(a[i].size() == a[i - 1].size());
  }
  for (int i = 1; i < b.size(); i++) {
    assert(b[i].size() == b[i - 1].size());
  }
  assert(a[0].size() == b.size());
  vector<vector<unsigned long long>> c(
      a.size(), vector<unsigned long long>(b[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        unsigned long long x = a[i][k], y = b[k][j];
        c[i][j] = add(c[i][j], mult(x, y));
      }
    }
  }
  return c;
}
inline void operator*=(vector<vector<unsigned long long>> &a,
                       vector<vector<unsigned long long>> b) {
  a = a * b;
}
vector<vector<unsigned long long>> bpow(vector<vector<unsigned long long>> a,
                                        unsigned long long b) {
  vector<vector<unsigned long long>> res = a;
  b--;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b /= 2;
  }
  return res;
}
int main() {
  int n;
  scanf("%d%lld", &n, &K);
  vector<unsigned long long> a;
  while (n--) {
    int x;
    scanf("%d", &x);
    if (x > 0 || a.size() > 0) a.push_back(x);
  }
  if (a.size() > 10) {
    int ans = 0;
    while (*max_element(a.begin(), a.end()) < K) {
      for (int i = 1; i < a.size(); i++) {
        a[i] = (a[i] + a[i - 1] < K ? a[i] + a[i - 1] : K);
      }
      cerr << ans << " " << a.back() << endl;
      ans++;
    }
    cout << ans;
  } else {
    if (*max_element(a.begin(), a.end()) >= K) {
      cout << 0;
    } else {
      vector<vector<unsigned long long>> M(
          a.size(), vector<unsigned long long>(a.size(), 0));
      for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
          M[i][j] = 1;
        }
      }
      unsigned long long l = 1, r = 1e18;
      while (l < r) {
        unsigned long long m = (l + r) / 2;
        vector<vector<unsigned long long>> cur =
            vector<vector<unsigned long long>>(1, a) * bpow(M, m);
        if (*max_element(cur[0].begin(), cur[0].end()) >= K) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      cout << l;
    }
  }
}
