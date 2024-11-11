#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int inf = (int)1e9 + 123;
const long long infl = (long long)1e18 + 123;
const double eps = 1e-10;
const int MAX_N = (int)3e5 + 123;
int n;
int a[130][10];
int cnt[10];
int calc(int x, int t) {
  if (t == inf) return 0;
  return x / 250 * (250 - t);
}
int find_pt(int p, int q) {
  for (int i = 5; i >= 0; i--) {
    int p2 = 1, q2 = (1 << i);
    if (1ll * p * q2 <= 1ll * p2 * q) return (i + 1) * 500;
  }
  assert(0);
}
pair<int, int> now[10];
void check(int add) {
  int first = 0, second = 0;
  for (int v = 1; v <= 5; v++) {
    int pt = find_pt(cnt[v] + add, n + add);
    if (a[1][v] < a[2][v] || a[1][v] == inf) {
      pt = find_pt(cnt[v], n + add);
    }
    first += calc(pt, a[1][v]);
    second += calc(pt, a[2][v]);
  }
  if (first > second) {
    cout << add << endl;
    exit(0);
  }
}
void rec(int v, int add, int used = 0, int first = 0, int second = 0) {
  if (used > add) return;
  if (v == 6) {
    if (first > second) {
      cout << add << endl;
      exit(0);
    }
    return;
  }
  if (a[1][v] < a[2][v] || a[1][v] == inf) {
    int pt = find_pt(cnt[v], n + add);
    now[v] = make_pair(cnt[v], n + add);
    rec(v + 1, add, used, first + calc(pt, a[1][v]),
        second + calc(pt, a[2][v]));
    return;
  }
  int pt = find_pt(cnt[v] + add, n + add);
  rec(v + 1, add, used, first + calc(pt, a[1][v]), second + calc(pt, a[2][v]));
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
      if (a[i][j] != -1) cnt[j]++;
    }
  }
  int best[3] = {0, 0, 0};
  for (int i = 1; i <= 5; i++) {
    if (a[1][i] == -1) a[1][i] = inf;
    if (a[2][i] == -1) a[2][i] = inf;
    int pt = (a[1][i] < a[2][i] ? 3000 : 500);
    best[1] += calc(pt, a[1][i]);
    best[2] += calc(pt, a[2][i]);
  }
  if (best[1] <= best[2]) {
    cout << "-1" << endl;
    return 0;
  }
  for (int ans = 1; ans <= (int)1e5; ans++) {
    check(ans);
  }
  cout << "-1" << endl;
  return 0;
}
