#include <bits/stdc++.h>
using namespace std;
int n, len, k;
long long int a[200000];
int rev[200000];
vector<pair<int, int> > v;
long long int BIT[200000];
int BIT2[200000];
long long int pre[200000];
void U(int loc, int val, int val2) {
  loc += 5;
  for (int i = loc; i < 200000; i += (i & -i)) {
    BIT[i] += val;
    BIT2[i] += val2;
  }
}
long long int Q(int loc) {
  long long int ret = 0;
  loc += 5;
  for (int i = loc; i > 0; i -= (i & -i)) ret += BIT[i];
  return ret;
}
int Qf(int loc) {
  int ret = 0;
  loc += 5;
  for (int i = loc; i > 0; i -= (i & -i)) ret += BIT2[i];
  return ret;
}
int getK(int K) {
  int lb = 0, ub = 200000 - 10, mid, ans = -1;
  while (lb <= ub) {
    mid = (lb + ub) / 2;
    if (Qf(mid) >= K) {
      ans = mid;
      ub = mid - 1;
    } else
      lb = mid + 1;
  }
  return ans;
}
void clear() {
  v.clear();
  memset(rev, 0, sizeof(rev));
  memset(BIT, 0, sizeof(BIT));
  memset(BIT2, 0, sizeof(BIT2));
  memset(pre, 0, sizeof(pre));
}
int main() {
  int i;
  cin >> n >> len;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    pre[i + 1] = pre[i] + a[i];
    v.push_back(make_pair(a[i], -i));
  }
  sort(v.begin(), v.end());
  for (i = 0; i < n; i++) rev[-v[i].second] = i;
  cin >> k;
  k = min(k, len);
  for (i = 0; i < len; i++) U(rev[i], min(0LL, a[i]), 1);
  long long int cans = pre[len] - 2 * Q(getK(k));
  for (i = len; i < n; i++) {
    U(rev[i - len], -min(0LL, a[i - len]), -1);
    U(rev[i], min(0LL, a[i]), 1);
    cans = max(cans, pre[i + 1] - pre[i - len + 1] - 2 * Q(getK(k)));
  }
  clear();
  for (i = 0; i < n; i++) {
    a[i] = -a[i];
    pre[i + 1] = pre[i] + a[i];
    v.push_back(make_pair(a[i], -i));
  }
  sort(v.begin(), v.end());
  for (i = 0; i < n; i++) rev[-v[i].second] = i;
  k = min(k, len);
  for (i = 0; i < len; i++) U(rev[i], min(0LL, a[i]), 1);
  cans = max(cans, pre[len] - 2 * Q(getK(k)));
  for (i = len; i < n; i++) {
    U(rev[i - len], -min(0LL, a[i - len]), -1);
    U(rev[i], min(0LL, a[i]), 1);
    cans = max(cans, pre[i + 1] - pre[i - len + 1] - 2 * Q(getK(k)));
  }
  cout << cans << endl;
  return 0;
}
