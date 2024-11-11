#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
map<int, int> pos;
int n, p[2002], s[2002], re, idx;
void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    pos[s[i]] = i;
  }
}
void solve() {
  input();
  idx = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == p[i]) continue;
    for (int j = i - 1; j >= 0; j--) {
      if (p[j] == s[i]) {
        int cur = j;
        for (int k = j + 1; k <= i; k++) {
          if (pos[p[k]] < k) {
            swap(p[cur], p[k]);
            re += k - cur;
            v.push_back(pair<int, int>(cur + 1, k + 1));
            cur = k;
          }
        }
        break;
      }
    }
  }
  printf("%d\n%d\n", re, v.size());
  for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
}
int main(void) {
  solve();
  return 0;
}
