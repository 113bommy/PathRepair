#include <bits/stdc++.h>
using namespace std;
int n, m;
long long t;
vector<long long> work, s_work;
pair<bool, int> f(int x) {
  if (x == 0) return make_pair(true, t);
  long long time = 0;
  long long target = s_work[x - 1];
  long long resttime = 0;
  int cnt = 0;
  for (int i = 0; i < work.size(); i++) {
    if (work[i] > target) continue;
    time += work[i];
    resttime += work[i];
    cnt++;
    x--;
    if (x == 0) break;
    if (cnt % 2 == 0) {
      time += resttime;
      resttime = 0;
      cnt = 0;
    }
  }
  return make_pair(time <= t, target);
}
int main() {
  int c;
  cin >> c;
  while (c--) {
    cin >> n >> m >> t;
    work.clear();
    work.resize(n);
    s_work.clear();
    s_work.resize(n);
    for (int i = 0; i < n; i++) cin >> work[i], s_work[i] = work[i];
    sort(s_work.begin(), s_work.end());
    if (s_work.front() > t) {
      cout << 0 << " " << t << endl;
      continue;
    }
    int l = 0, u = n + 1;
    while (u - l > 1) {
      int mid = (l + u) / 2;
      if (f(mid).first)
        l = mid;
      else
        u = mid;
    }
    cout << l << " " << f(l).second << endl;
  }
  return 0;
}
