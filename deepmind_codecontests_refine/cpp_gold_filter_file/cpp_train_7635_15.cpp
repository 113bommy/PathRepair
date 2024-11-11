#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
vector<int> v[1000];
int l[1000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    v[i].resize(l[i]);
    for (int j = 0; j < l[i]; j++) scanf("%d", &v[i][j]);
    sort((v[i]).begin(), (v[i]).end());
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int ai = (i + n - 1) % n;
    int bi = (i + 1) % n;
    int al = 0, ar = -1, bl = 0, br = -1;
    for (int j = 0; j + 1 < l[i]; j++) {
      while (al < l[ai] && v[ai][al] < v[i][j]) al++;
      while (ar + 1 < l[ai] && v[ai][ar + 1] <= v[i][j + 1]) ar++;
      while (bl < l[bi] && v[bi][bl] < v[i][j]) bl++;
      while (br + 1 < l[bi] && v[bi][br + 1] <= v[i][j + 1]) br++;
      int ac = max(ar - al + 1, 0), bc = max(br - bl + 1, 0);
      if (ac != bc) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
