#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7, INF = 1e9;
const long long MOD = 1e9 + 7;
int t, n, d, cur, now_on, new_dad;
int low_bound, high_bound;
void HighIt() {
  low_bound = 0;
  int depth = 0;
  for (int i = 1; i < n + 1; i++) {
    if (!(i & (i - 1))) depth++;
    low_bound += depth - 1;
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> d;
    high_bound = n * (n - 1) >> 1;
    HighIt();
    if (d < low_bound || d > high_bound) {
      cout << "NO" << endl;
      continue;
    }
    vector<int> bad(n);
    vector<int> par(n);
    iota(par.begin(), par.end(), -1);
    vector<int> dep(n);
    iota(dep.begin(), dep.end(), 0);
    vector<int> cnt(n, 1);
    cnt[n - 1] = 0;
    int cur = high_bound;
    while (cur > d) {
      now_on = -1;
      for (int i = 0; i < n; i++)
        if (!bad[i] && cnt[i] == 0 && (now_on == -1 || dep[now_on] > dep[i]))
          now_on = i;
      new_dad = -1;
      for (int i = 0; i < n; i++) {
        if (cnt[i] < 2 && dep[i] < dep[now_on] - 1 &&
            (new_dad == -1 || dep[new_dad] < dep[i]))
          new_dad = i;
      }
      if (new_dad == -1) {
        bad[now_on] = 1;
        continue;
      }
      cnt[par[now_on]]--;
      dep[now_on]--;
      cnt[new_dad]++;
      par[now_on] = new_dad;
      cur--;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << par[i] + 1 << ' ';
    cout << endl;
  }
}
