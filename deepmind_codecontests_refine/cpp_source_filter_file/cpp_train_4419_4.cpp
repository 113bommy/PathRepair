#include <bits/stdc++.h>
using namespace std;
struct request {
  int id;
  int c;
  int p;
};
struct table {
  int id;
  int size;
  bool isUsed;
};
request rs[1001];
table ts[1001];
pair<int, int> q_r[1001];
bool cmp_re(const request &a, const request &b) {
  if (a.p < b.p)
    return true;
  else if (a.p == b.p) {
    return a.c < b.c;
  } else {
    return false;
  }
}
bool cmp_t(const table &a, const table &b) { return a.size > b.size; }
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &rs[i].c, &rs[i].p);
    rs[i].id = i;
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &ts[i].size);
    ts[i].id = i;
    ts[i].isUsed = true;
  }
  sort(rs + 1, rs + n + 1, cmp_re);
  sort(ts + 1, ts + k + 1, cmp_t);
  int cnt = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (rs[i].c <= ts[j].size && ts[j].isUsed) {
        ts[j].isUsed = false;
        sum += rs[i].p;
        q_r[cnt++] = make_pair(rs[i].id, ts[j].id);
        break;
      }
    }
  }
  printf("%d %d\n", cnt, sum);
  for (int i = 0; i < cnt; i++) {
    printf("%d %d\n", q_r[i].first, q_r[i].second);
  }
  return 0;
}
