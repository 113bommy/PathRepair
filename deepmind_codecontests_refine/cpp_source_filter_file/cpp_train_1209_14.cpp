#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
const int MAXQ = 200100;
const int MAXA = 1000100;
int n, q, sn;
long long a[MAXN], f[MAXA], ans[MAXQ], curAns;
pair<pair<int, int>, int> qq[MAXQ];
bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
  if (p1.first.first / sn != p2.first.first / sn) {
    return p1.first.first / sn < p2.first.first / sn;
  }
  return p1.first.second < p2.first.second;
}
void add(int i) {
  curAns += 2 * a[i] * f[a[i]] + a[i];
  f[a[i]]++;
}
void rem(int i) {
  curAns += -2 * a[i] * f[a[i]] + a[i];
  f[a[i]]--;
}
int main() {
  ios_base::sync_with_stdio(false);
  if (fopen("test.in", "r")) {
    freopen("test.in", "r", stdin);
  }
  cin.tie(NULL);
  scanf("%d %d", &n, &q);
  sn = (int)sqrt(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &qq[i].first.first, &qq[i].first.second);
    qq[i].first.first--;
    qq[i].first.second--;
    qq[i].second = i;
  }
  sort(qq, qq + q, cmp);
  int cl = 0, cr = 0;
  add(0);
  for (int i = 0; i < q; i++) {
    int l = qq[i].first.first, r = qq[i].first.second;
    while (cl < l) {
      rem(cl++);
    }
    while (cl > l) {
      add(--cl);
    }
    while (cr < r) {
      add(++cr);
    }
    while (cr > r) {
      rem(cr--);
    }
    ans[qq[i].second] = curAns;
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
