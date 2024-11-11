#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 9;
vector<int> v[22], tp;
bool o[N];
int a[N], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < 22; ++j) {
      if (a[i] & (1 << j)) {
        v[j].push_back(i);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int c = a[i];
    for (int j = 0; j < 22; ++j)
      if (c & (1 << j)) v[j].pop_back();
    tp.clear();
    for (int j = 0; j < 22; ++j) {
      if (c & (1 << j))
        ;
      else {
        if (int(v[j].size()) > 0) tp.push_back(v[j].back());
      }
    }
    sort(tp.begin(), tp.end());
    o[c] = 1;
    for (int i = 0; i < int(tp.size()); ++i) {
      o[c |= a[tp[i]]] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) ans += o[i];
  cout << ans << endl;
  return 0;
}
