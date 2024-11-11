#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int MAXN = 110001;
int a[MAXN];
int cnt[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int N;
  cin >> N;
  for (int i = 0; i < (int)(N); ++i) cin >> a[i];
  set<int> q;
  for (int i = 0; i < (int)(N); ++i) {
    if (q.count(a[i]))
      q.erase(a[i]);
    else
      q.insert(a[i]);
  }
  if (q.size() > 1) {
    cout << 0 << '\n';
    return 0;
  }
  bool eq = true;
  for (int i = 0; i < N / 2; ++i) {
    if (a[i] != a[N - i - 1]) {
      eq = false;
      break;
    }
  }
  if (eq) {
    cout << 1LL * N * (N + 1) / 2 << '\n';
    return 0;
  }
  long long ans = 0;
  int l = 0;
  while (a[l] == a[N - l - 1]) ++l;
  int r = (N - 1) / 2;
  while (a[r] == a[N - r - 1]) --r;
  int nzc = 0;
  for (int i = l; i < N / 2; ++i) {
    int x = a[i];
    if (cnt[x] != 0) --nzc;
    ++cnt[x];
    if (cnt[x] != 0) ++nzc;
    x = a[N - i - 1];
    if (cnt[x] != 0) --nzc;
    --cnt[x];
    if (cnt[x] != 0) ++nzc;
  }
  if (nzc == 0) {
    cout << 2LL * (l + 1) * (N - r) - 1LL * (l + 1) * (l + 1) << '\n';
    return 0;
  }
  for (int i = 0; i < (int)(MAXN); ++i) cnt[i] = 0;
  int nc = 0;
  for (int i = 0; i < (int)(N); ++i) {
    if (cnt[a[i]] == 0) ++nc;
    --cnt[a[i]];
  }
  int i1, i2;
  for (int i = 0; i < N; ++i) {
    if (cnt[a[i]] < 0) --nc;
    cnt[a[i]] += 2;
    if (cnt[a[i]] < 0) ++nc;
    if (nc == 0) {
      i1 = i;
      break;
    }
  }
  for (int i = 0; i < (int)(MAXN); ++i) cnt[i] = 0;
  nc = 0;
  for (int i = 0; i < (int)(N); ++i) {
    if (cnt[a[i]] == 0) ++nc;
    --cnt[a[i]];
  }
  for (int i = (int)(N)-1; i >= 0; --i) {
    if (cnt[a[i]] < 0) --nc;
    cnt[a[i]] += 2;
    if (cnt[a[i]] < 0) ++nc;
    if (nc == 0) {
      i2 = i;
      break;
    }
  }
  cout << 1LL * (l + 1) * (N - i1) + 1LL * (l + 1) * (i2 + 1) -
              1LL * (l + 1) * (l + 1)
       << '\n';
  return 0;
}
