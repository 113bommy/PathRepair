#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<pair<long long, int>, pair<int, int>> arr[N];
int TOT[N];
int CURR[N];
int Z[N];
int EX[N];
int ST[N], EN[N];
int G[N];
vector<pair<int, int>> vt[N];
vector<int> vx[N];
int bit[N];
int n;
int XX[N];
void add(int i, int v) {
  if (i == 0) return;
  while (i <= n) {
    bit[i] += v;
    i += (i & -i);
  }
}
int query(int i) {
  int sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= (i & -i);
  }
  return sum;
}
int gtS(int a, int b) {
  assert(b >= a);
  assert(a >= 1 && a <= n);
  assert(b >= 1 && b <= n);
  assert(EX[a] == EX[b]);
  return query(b) - query(a - 1);
}
int main() {
  int k, x, f, r;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &x, &r, &f);
    arr[i].first.first = x, arr[i].first.second = f, arr[i].second.first = r;
    arr[i].second.second = i;
  }
  sort(arr + 1, arr + 1 + n);
  for (int i = 1; i <= n; i++) {
    arr[i].second.second = i;
  }
  long long hh;
  for (int i = 1; i <= n; i++) {
    hh = arr[i].first.first;
    arr[i].first.first = arr[i].first.second;
    arr[i].first.second = hh;
  }
  sort(arr + 1, arr + 1 + n);
  for (int i = 1; i <= n; i++) {
    XX[arr[i].second.second] = arr[i].first.second;
    Z[arr[i].second.second] = i;
    f = arr[i].first.first;
    EX[i] = f;
    vt[f].push_back({arr[i].first.second, i});
    if (i == 1 || arr[i].first.first != arr[i - 1].first.first) ST[f] = i;
    TOT[f]++;
    EN[f] = i;
  }
  for (int i = 1; i <= n; i++) {
    hh = arr[i].first.first;
    arr[i].first.first = arr[i].first.second;
    arr[i].first.second = hh;
  }
  sort(arr + 1, arr + 1 + n);
  long long ans = 0;
  arr[n + 1].first.first = 1e18;
  for (int i = 1; i <= n; i++) {
    assert(XX[i] == arr[i].first.first);
    for (auto c : vx[i]) {
      add(c, -1);
    }
    f = arr[i].first.second;
    assert(EN[f] - ST[f] + 1 == TOT[f]);
    assert(arr[i].first.first > G[f]);
    for (int j = f - k; j <= f + k; j++) {
      if (j <= 0) continue;
      assert(CURR[j] <= vt[j].size());
      assert(arr[i].first.first > G[j]);
      if (CURR[j] > 0 && arr[i].first.first - G[j] <= arr[i].second.first) {
        int lx = 0, rx = CURR[j] - 1, mx;
        while (lx < rx) {
          mx = (lx + rx) / 2;
          if (arr[i].first.first - vt[j][mx].first <= arr[i].first.first) {
            rx = mx;
          } else
            lx = mx + 1;
        }
        assert(lx < vt[j].size());
        ans += gtS(vt[j][lx].second, vt[j][CURR[j] - 1].second);
        assert(query(EN[j]) == query(vt[j][CURR[j] - 1].second));
      }
    }
    add(Z[i], 1);
    int lx = i + 1, rx = n + 1, mx;
    while (lx < rx) {
      mx = (lx + rx) / 2;
      if ((long long)arr[mx].first.first - arr[i].first.first >
          (long long)arr[i].second.first)
        rx = mx;
      else
        lx = mx + 1;
    }
    vx[lx].push_back(Z[i]);
    CURR[f]++;
    G[f] = arr[i].first.first;
  }
  cout << ans << endl;
  return 0;
}
