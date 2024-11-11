#include <bits/stdc++.h>
using namespace std;
int n, s[2005];
vector<pair<int, int> > v;
bool used[2005];
int main() {
  memset(used, 0, sizeof used);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    if (s[i] < 0) s[i] = -s[i];
    v.push_back(pair<int, int>(s[i], -i));
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int pos = -v[i].second;
    used[pos] = 1;
    int t1 = 0, t2 = 0;
    for (int j = 0; j < pos; j++)
      if (used[j] == 0) t1++;
    for (int j = pos + 1; j < n; j++)
      if (used[j] == 0 && s[i] != s[j]) t2++;
    if (t1 <= t2) {
      ans += t1;
    } else {
      ans += t2;
    }
  }
  printf("%d\n", ans);
  return 0;
}
