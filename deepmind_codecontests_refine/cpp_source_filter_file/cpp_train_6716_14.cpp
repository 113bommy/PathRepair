#include <bits/stdc++.h>
using namespace std;
void trace(long long a[], int second, int e) {
  for (int i = second; i <= e; i++) {
    cout << a[i] << "  ";
  }
  cout << endl;
}
const int lim = 1e5 + 5;
const int M = 1e9 + 7;
typedef struct i {
  long long cost, no;
} i;
int finald, finalp;
long long d, p, dc[lim], pc[lim], adc[lim], apc[lim], m, n, k, second;
i pitem[lim], ditem[lim];
bool cmp(i a, i b) { return a.cost < b.cost; }
bool check(int dno) {
  long long nod, nop;
  if (d >= k) {
    nod = k;
    nop = 0;
  } else {
    nod = d;
    nop = k - d;
  }
  long long tot = ditem[nod].cost * dc[dno] + pitem[nop].cost * pc[dno];
  while (tot > second && nod >= 1 && nop < p) {
    nod--;
    nop++;
    tot = ditem[nod].cost * dc[dno] + pitem[nop].cost * pc[dno];
  }
  if (tot <= second) {
    finald = nod;
    finalp = nop;
    return 1;
  } else
    return 0;
}
int solve() {
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, cost;
  cin >> n >> m >> k >> second;
  if (m < k) {
    cout << -1;
    return 0;
  }
  dc[0] = pc[0] = LLONG_MAX;
  d = 1;
  p = 1;
  for (i = 1; i <= n; i++) {
    cin >> adc[i];
    dc[i] = min(adc[i], dc[i - 1]);
  }
  for (i = 1; i <= n; i++) {
    cin >> apc[i];
    pc[i] = min(apc[i], pc[i - 1]);
  }
  for (i = 1; i <= m; i++) {
    cin >> t >> cost;
    if (t == 1) {
      ditem[d].no = i;
      ditem[d++].cost = cost;
    } else {
      pitem[p].no = i;
      pitem[p++].cost = cost;
    }
  }
  sort(ditem + 1, ditem + d, cmp);
  sort(pitem + 1, pitem + p, cmp);
  for (i = 1; i < d; i++) ditem[i].cost += ditem[i - 1].cost;
  for (i = 1; i < p; i++) pitem[i].cost += pitem[i - 1].cost;
  d--;
  p--;
  int minday = solve();
  cout << minday << endl;
  long long md = 1, mp = 1;
  for (i = 2; i <= minday; i++) {
    if (adc[md] > adc[i]) {
      md = i;
    }
  }
  for (i = 1; i <= minday; i++) {
    if (apc[md] > apc[i]) {
      mp = i;
    }
  }
  for (i = 1; i <= finald; i++) cout << ditem[i].no << " " << md << endl;
  for (i = 1; i <= finalp; i++) cout << pitem[i].no << " " << mp << endl;
  return 0;
}
