#include <bits/stdc++.h>
using namespace std;
int n, l, l1;
long long m, k;
pair<int, long long> C[5000005];
pair<int, long long> Tm[5000005];
int lc, t;
long long sc;
pair<int, long long> S[5000005];
long long ss;
void solve(long long e) {
  bool band = false;
  bool band1 = false;
  while (e) {
    if (e & 1) {
      ss += sc;
      if (!band1) {
        for (int i = 1; i <= lc; i++) {
          if (S[t].first == C[i].first) {
            S[t].second += C[i].second;
          } else {
            t++;
            S[t] = C[i];
          }
          while (S[t].second >= k) {
            long long y = S[t].second / k;
            S[t].second -= k * y;
            ss += k * y;
            if (!S[t].second) t--;
          }
        }
      }
    }
    e /= 2;
    sc += sc;
    if (band) continue;
    for (int i = 1; i <= lc; i++) Tm[i] = C[i];
    int lct = lc;
    for (int i = 1; i <= lct; i++) {
      if (C[lc].first == Tm[i].first) {
        C[lc].second += Tm[i].second;
      } else {
        lc++;
        C[lc] = Tm[i];
      }
      while (C[lc].second >= k) {
        long long y = C[lc].second / k;
        C[lc].second -= k * y;
        sc += k * y;
        if (!C[lc].second) lc--;
      }
    }
    int dif = max(2 * lct - lc + 2, 500);
    if (2 * dif >= lc) continue;
    C[dif - 1] = pair<int, long long>(0, 0);
    for (int i = 1; i <= dif; i++) {
      C[dif + i] = C[lc - dif + i];
    }
    lc = 2 * dif;
  }
}
int main() {
  cin >> n >> k >> m;
  int a;
  lc = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (C[lc].first == a) {
      C[lc].second++;
    } else {
      lc++;
      C[lc] = pair<int, long long>(a, 1);
      while (C[lc].second >= k) {
        C[lc].second -= k;
        sc += k;
        if (!C[lc].second) lc--;
      }
    }
  }
  if (lc == 1) {
    cout << ((n * m) % k);
    return 0;
  }
  solve(m);
  cout << n * m - ss;
  return 0;
}
