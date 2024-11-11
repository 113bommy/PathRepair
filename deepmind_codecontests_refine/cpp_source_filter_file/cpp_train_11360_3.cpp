#include <bits/stdc++.h>
using namespace std;
pair<bool, int> para(int n, int* p, int m, int d, long long t) {
  long long time = 0;
  int num = 0;
  int tottime = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] > d) continue;
    cnt++;
    if (num == m) {
      time += tottime;
      num = 1;
      tottime = p[i];
      time += p[i];
      if (time > t) return {0, cnt - 1};
    } else {
      num++;
      tottime += p[i];
      time += p[i];
      if (time > t) return {0, cnt - 1};
    }
  }
  return {1, cnt};
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, m, t;
    cin >> n >> m >> t;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    long long st = 0;
    long long en = min(200000ll, t);
    while (st < en) {
      long long mid = (st + en + 1) / 2;
      auto pp = para(n, p, m, mid, t);
      if (!pp.first)
        en = mid - 1;
      else
        st = mid;
    }
    auto pp = para(n, p, m, st, t);
    auto pp2 = para(n, p, m, st + 1, t);
    if (pp.second > pp2.second or st == t)
      cout << pp.second << ' ' << st << '\n';
    else
      cout << pp2.second << ' ' << st + 1 << '\n';
  }
}
