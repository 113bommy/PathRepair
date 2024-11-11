#include <bits/stdc++.h>
using namespace std;
int go(vector<int> const &v, int i = 29) {
  if (i == -1) {
    return 0;
  }
  vector<int> l, r;
  for (int j = 0; j < v.size(); j++) {
    if ((v[j] >> i) & 1) {
      l.push_back(v[j]);
    } else {
      r.push_back(v[j]);
    }
  }
  if (l.empty() || r.empty()) {
    if (l.size() > 0) {
      return go(l, i - 1);
    } else {
      return go(r, i - 1);
    }
  }
  return 1 << i + min(go(l, i - 1), go(r, i - 1));
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v;
  for (int i = 0; i < (int)(n); ++i) {
    int t;
    scanf("%d", &t);
    v.push_back(t);
  }
  printf("%d\n", go(v));
}
