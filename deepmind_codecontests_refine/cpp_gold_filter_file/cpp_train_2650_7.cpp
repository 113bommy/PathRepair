#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1.2e9;
long long l, r, k;
long long f(vector<long long> cur) {
  long long res = 0;
  for (int i = 0; i < (int)cur.size(); i++) {
    res ^= cur[i];
  }
  return res;
}
vector<long long> ans;
long long ansf;
void updAns(vector<long long> cur) {
  if (cur.size() > k) {
    return;
  }
  sort(cur.begin(), cur.end());
  for (int i = 0; i < (int)cur.size(); i++) {
    if (!(l <= cur[i] && cur[i] <= r)) {
      return;
    }
  }
  for (int i = 1; i < (int)cur.size(); i++) {
    if (cur[i] == cur[i - 1]) {
      return;
    }
  }
  if (f(cur) < ansf) {
    ans = cur;
    ansf = f(ans);
  }
}
int main() {
  cin >> l >> r >> k;
  ansf = (long long)1e18;
  vector<long long> cur;
  cur.clear();
  cur.push_back(l);
  updAns(cur);
  if (r - l + 1 <= 10) {
    int n = r - l + 1;
    cur.clear();
    for (int mask = 1; mask < (1 << n); mask++) {
      long long f = 0;
      for (int i = 0; i < n; i++) {
        if ((1 << i) & mask) {
          cur.push_back(l + i);
        }
      }
      updAns(cur);
    }
  }
  cur.clear();
  long long p = (-l) & 1;
  for (int i = 0; i < 4; i++) {
    cur.push_back(p + i + l);
  }
  updAns(cur);
  cur.clear();
  p = (-l) & 1;
  for (int i = 0; i < 2; i++) {
    cur.push_back(p + i + l);
  }
  updAns(cur);
  for (int i = 50; i >= 0; i--) {
    long long p = (1ll << i);
    cur.clear();
    cur.push_back(p * 2 - 1);
    cur.push_back(p * 3 - 1);
    cur.push_back(p * 3);
    updAns(cur);
  }
  cout << ansf << endl;
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
