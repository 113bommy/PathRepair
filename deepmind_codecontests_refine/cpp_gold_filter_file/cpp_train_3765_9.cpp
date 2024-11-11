#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5) + 99;
const pair<long long, long long> zero = make_pair(0, 0);
int n;
int a[N];
pair<long long, long long> hsh[N], sumHsh[N];
pair<long long, long long> prefsum[N];
void upd(pair<long long, long long> &a, pair<long long, long long> b) {
  a.first ^= b.first;
  a.second ^= b.second;
}
pair<long long, long long> f(int l, int r) {
  pair<long long, long long> res = prefsum[r];
  if (l > 0) upd(res, prefsum[l - 1]);
  return res;
}
int calc(int pos) {
  int r = pos, len = 0, res = 0;
  while (r < n - 1 && a[r + 1] != 0) {
    len = max(len, a[r + 1] + 1);
    ++r;
    if (r - len + 1 >= 0 && f(r - len + 1, r) == sumHsh[len - 1]) ++res;
  }
  return res;
}
int main() {
  long long x = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    x ^= a[i];
  }
  mt19937 rnd(time(NULL));
  for (int i = 0; i < N; ++i) {
    hsh[i].first = (rnd() ^ x) & ((1LL << 30) - 1);
    hsh[i].second = 0;
    sumHsh[i] = hsh[i];
    if (i > 0) upd(sumHsh[i], sumHsh[i - 1]);
  }
  int res = 0;
  for (int tc = 0; tc < 2; ++tc) {
    for (int i = 0; i < n; ++i) {
      prefsum[i] = hsh[a[i]];
      if (i > 0) upd(prefsum[i], prefsum[i - 1]);
    }
    for (int i = 0; i < n; ++i)
      if (a[i] == 0) res += calc(i) + (tc == 0);
    reverse(a, a + n);
  }
  cout << res << endl;
  return 0;
}
