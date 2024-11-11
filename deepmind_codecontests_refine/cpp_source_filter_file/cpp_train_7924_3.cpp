#include <bits/stdc++.h>
using namespace std;
long long pl, pr, vl, vr, k;
vector<long long> lu;
void init() {
  for (int l = 1; l <= 9; l++) {
    for (int mask = 0; mask < (1 << l); mask++) {
      long long num = 0;
      for (int i = 0; i < l; i++) {
        if (mask & (1 << i))
          num = num * 10 + 4;
        else
          num = num * 10 + 7;
      }
      lu.push_back(num);
    }
  }
  lu.push_back(1);
  sort(lu.begin(), lu.end());
}
vector<bool> used;
int main() {
  cin >> pl >> pr >> vl >> vr >> k;
  init();
  used.resize(lu.size());
  double ans = 0.0;
  for (int i = 0; i + 1 < lu.size(); i++) {
    long long l = lu[i] + 1, r = lu[i + 1] - 1;
    l = max(pl, l), r = min(r, pr);
    if (l <= r) {
      int j = i - k;
      if (j >= 0) {
        long long nl = lu[j] + 1, nr = lu[j + 1];
        if (j == 0) nl = 1;
        nl = max(vl, nl), nr = min(nr, vr);
        long long q = 0;
        if (nr >= nl) {
          q = nr - nl + 1;
          used[j] = 1;
        }
        ans += 1.0 * (r - l + 1) * q;
      }
    }
    l = lu[i] + 1, r = lu[i + 1] - 1;
    if (i == 0) l = 1;
    l = max(pl, l), r = min(r, pr);
    if (l <= r) {
      int j = i + k;
      if (j + 1 < lu.size()) {
        long long nl = lu[j], nr = lu[j + 1] - 1;
        nl = max(vl, nl), nr = min(nr, vr);
        long long q = 0;
        if (nr >= nl) {
          q = nr - nl + 1;
          used[j] = 1;
        }
        ans += 1.0 * (r - l + 1) * q;
      }
    }
  }
  for (int i = 1; i < lu.size(); i++) {
    if (lu[i] <= pr && lu[i] >= pl) {
      int j = i + k - 1;
      if (j + 1 < lu.size()) {
        long long nl = lu[j], nr = lu[j + 1] - 1;
        nl = max(vl, nl), nr = min(nr, vr);
        long long q = 0;
        if (nr >= nl) {
          q = nr - nl + 1;
          used[j] = 1;
        }
        ans += 1.0 * q;
      }
      j = i - k;
      if (j >= 0) {
        long long nl = lu[j] + 1, nr = lu[j + 1];
        if (j == 0) nl = 1;
        nl = max(vl, nl), nr = min(nr, vr);
        long long q = 0;
        if (nr >= nl) {
          if (nr == lu[i]) nr--;
          if (nr >= nl) {
            q = nr - nl + 1;
            used[j] = 1;
          }
        }
        ans += 1.0 * q;
      }
    }
  }
  printf("%.9lf\n", ans / (pr - pl + 1) / (vr - vl + 1));
  return 0;
}
