#include <bits/stdc++.h>
int c[5005];
int pair[5005];
int cnt[105];
using namespace std;
class Elem {
 public:
  int color;
  int cnt;
  Elem(int color, int cnt) {
    this->color = color;
    this->cnt = cnt;
  }
};
bool cmp(const Elem &a, const Elem &b) { return a.cnt > b.cnt; }
int main(int argc, const char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int> > color_children(m + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    color_children[c[i]].push_back(i);
    cnt[c[i]]++;
  }
  vector<Elem> v;
  for (int i = 1; i <= m; i++) {
    if (cnt[i] > 0) {
      v.push_back(Elem(i, cnt[i]));
    }
  }
  sort(v.begin(), v.end(), cmp);
  int aux[n + 1], idx = 0, begin_idx[m + 1];
  begin_idx[v[0].color] = 1;
  int aux2[n + 1];
  for (int i = 0; i < v.size(); i++) {
    if (i >= 1) {
      begin_idx[v[i].color] = begin_idx[v[i - 1].color] + v[i - 1].cnt;
    }
    for (int j = 0; j < v[i].cnt; j++) {
      aux[++idx] = v[i].color;
      int new_idx = idx + n - v[0].cnt;
      if (new_idx > n) {
        new_idx = new_idx - n;
      }
      aux2[new_idx] = aux[idx];
    }
  }
  if (v[0].cnt <= n / 2) {
    printf("%d\n", n);
  } else {
    printf("%d\n", n - (v[0].cnt * 2 - n));
  }
  for (int i = 1; i <= n; i++) {
    int new_idx = begin_idx[c[i]] + n - v[0].cnt;
    if (new_idx > n) {
      new_idx = new_idx - n;
    }
    printf("%d %d\n", c[i], aux2[begin_idx[c[i]]]);
    begin_idx[c[i]]++;
  }
  return 0;
}
