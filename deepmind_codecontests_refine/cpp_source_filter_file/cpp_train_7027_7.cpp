#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, id;
  bool operator<(const node& tmp) const { return v < tmp.v; }
};
vector<node> fi;
vector<node> se;
long long ans;
int mark[200005], k;
int cnt, q, w;
int qi[5];
bool check(int a, int b, int c, int d) {
  memset(mark, 0, sizeof(mark));
  cnt = 0;
  int i;
  for (i = 0; i < a; i++) {
    mark[fi[i].id]++;
    if (mark[fi[i].id] == 1) cnt++;
  }
  for (i = 0; i < b; i++) {
    mark[se[i].id]++;
    if (mark[se[i].id] == 1) cnt++;
  }
  for (i = q - 1; i > c; i--) {
    mark[fi[i].id]++;
    if (mark[fi[i].id] == 1) cnt++;
  }
  for (i = w - 1; i > d; i--) {
    mark[se[i].id]++;
    if (mark[se[i].id] == 1) cnt++;
  }
  if (cnt <= k) return 1;
  return 0;
}
int main() {
  int n, m, i, j, a, b, c, d;
  cin >> n >> k;
  ans = 2000000007;
  ans *= 2000000007;
  for (i = 1; i <= n; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    fi.push_back((node){a + c, i});
    se.push_back((node){b + d, i});
  }
  sort(fi.begin(), fi.end());
  sort(se.begin(), se.end());
  q = fi.size();
  w = se.size();
  for (i = 0; i < min(k + 1, q); i++) {
    if (i != 0 && fi[i].v == fi[i - 1].v) continue;
    for (j = 0; j < min(k + 1, w); j++) {
      if (j != 0 && se[j].v == se[j - 1].v) continue;
      for (a = q - 1; a >= max(q - 1 - k, i); a--) {
        if (a != q - 1 && fi[a].v == fi[a + 1].v) continue;
        for (b = w - 1; b >= max(w - 1 - k, j); b--) {
          if (b != w - 1 && se[b].v == se[b + 1].v) continue;
          if (check(i, j, a, b)) {
            int L = (se[b].v - se[j].v);
            if (L == 0) L += 2;
            int R = (fi[a].v - fi[i].v);
            if (R == 0) R += 2;
            ans = min(ans, 1LL * L * R / 4);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
