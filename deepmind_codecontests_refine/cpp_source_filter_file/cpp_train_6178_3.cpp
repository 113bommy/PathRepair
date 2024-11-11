#include <bits/stdc++.h>
using namespace std;
int n, m, loc[250] = {}, isi[250] = {}, idx = 0;
int kosong() {
  for (int i = 0, _n = (n); i < _n; i++)
    if (isi[i] == -1) return i;
  return -111;
}
int main() {
  memset(isi, -1, sizeof isi);
  scanf("%d %d", &n, &m);
  for (int i = 0, _n = (m); i < _n; i++) {
    int a;
    scanf("%d", &a);
    for (int j = 0, _n = (a); j < _n; j++) {
      int x;
      scanf("%d", &x);
      x--;
      isi[x] = idx;
      loc[idx] = x;
      idx++;
    }
  }
  vector<pair<int, int> > ans;
  for (int i = 0, _n = (idx); i < _n; i++)
    if (isi[i] != i) {
      if (isi[i] == -1) {
        ans.push_back(make_pair(loc[i], i));
        isi[loc[i]] = -1;
        loc[i] = i;
        isi[i] = i;
      } else {
        int k = kosong();
        ans.push_back(make_pair(i, k));
        isi[k] = i;
        loc[isi[i]] = k;
        isi[i] = -1;
        i--;
      }
    }
  printf("%d\n", ans.size());
  for (int i = 0, _n = (ans.size()); i < _n; i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}
