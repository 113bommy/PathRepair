#include <bits/stdc++.h>
using namespace std;
int n, A, cf, cm;
pair<int, int> a[100010];
long long sum[100010], m;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int getPos(int l, int r, int val) {
  int ret = r + 1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (a[mid].first >= val) {
      ret = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ret;
}
int cal(int Lim) {
  int l = 0, r = A;
  long long cur = A * (n - Lim) - (sum[n] - sum[Lim]);
  if (cur > m) return -1;
  int score = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    int pos = getPos(0, Lim - 1, mid);
    if (cur + (pos * 1ll * mid - sum[pos]) <= m) {
      score = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return score;
}
long long getPoint(int score, int r) {
  return score * 1ll * cm + (n - r) * 1ll * cf;
}
void solve() {
  int l = 0, r = n, cur = m, score = 0;
  int ansR, ansScore;
  long long ans = -1;
  for (int r = n; r >= 0; r--) {
    score = cal(r);
    if (score < 0) break;
    if (getPoint(score, r) >= ans) {
      ans = getPoint(score, r);
      ansR = r;
      ansScore = score;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < (n); i++) {
    if (a[i].first < ansScore) a[i].first = ansScore;
    if (i >= ansR) a[i].first = A;
  }
  sort(a, a + n, cmp);
  for (int i = 0; i < (n); i++)
    printf("%d%c", a[i].first, i == n - 1 ? '\n' : ' ');
}
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 0; i < (n); i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < (n); i++) sum[i + 1] = sum[i] + a[i].first;
  solve();
  return 0;
}
