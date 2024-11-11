#include <bits/stdc++.h>
using namespace std;
int key[110000], ka[110000];
long long sum[110000];
vector<vector<int> > tr;
vector<pair<int, int> > cl;
map<int, int> pre, nex;
void rec(long long sum_, int ka_, int it) {
  ka[it] = ka_;
  sum[it] = sum_;
  if (tr[it].size() < 1) return;
  int x = tr[it][0], y = tr[it][1];
  if (key[x] > key[y]) {
    rec(sum_ + pre[key[it]], ka_ + 1, x);
    rec(sum_ + nex[key[it]], ka_ + 1, y);
  } else {
    rec(sum_ + pre[key[it]], ka_ + 1, y);
    rec(sum_ + nex[key[it]], ka_ + 1, x);
  }
  return;
}
int main() {
  int i, n, m, a, to;
  cin >> n;
  vector<int> tm;
  for (i = 0; i < n + 10; i++) tr.push_back(tm);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &key[i + 1]);
    if (a < 0)
      to = i + 1;
    else
      tr[a].push_back(i + 1);
    cl.push_back(make_pair(key[i + 1], i + 1));
  }
  sort(cl.begin(), cl.end());
  for (i = 1; i < n - 1; i++) {
    pre[cl[i].first] = cl[i - 1].first;
    nex[cl[i].first] = cl[i + 1].first;
  }
  rec(0, 0, to);
  cin >> m;
  for (i = 0; i < m; i++) {
    scanf("%d", &a);
    int hi = n - 1, lo = 0, it;
    while (hi > lo) {
      int mi = (lo + hi + 1) / 2;
      if (cl[mi].first > a)
        hi = mi - 1;
      else
        lo = mi;
    }
    if (hi < 1 || hi > n - 2)
      it = cl[hi].second;
    else {
      if (tr[cl[hi].second].size() < 1)
        it = cl[hi].second;
      else
        it = cl[hi + 1].second;
    }
    printf("%.12f\n", 1.0 * sum[it] / ka[it]);
  }
  return 0;
}
