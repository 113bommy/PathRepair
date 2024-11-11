#include <bits/stdc++.h>
using namespace std;
char s[1000001], ans[1000001];
int n, k;
int z[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  vector<pair<int, int> > anss;
  for (int pos = k; pos <= n; pos += k) {
    int l = pos / k;
    if (z[l] >= pos - l) {
      anss.push_back(make_pair(pos - 1, pos + min(z[pos], l) - 1));
    }
  }
  sort(anss.begin(), anss.end());
  for (int i = 0; i < n; ++i) ans[i] = '0';
  int big = 0;
  for (int i = 0; i < anss.size(); ++i) {
    int beg = anss[i].first, end = anss[i].second;
    if (end < big) continue;
    beg = max(beg, big);
    for (int j = beg; j <= end; ++j) ans[j] = '1';
    big = max(big, end);
  }
  printf("%s", ans);
  return 0;
}
