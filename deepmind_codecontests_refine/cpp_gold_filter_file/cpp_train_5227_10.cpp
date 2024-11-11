#include <bits/stdc++.h>
using namespace std;
const int maxN = 2000 + 5;
char s[maxN];
int t, n, k;
vector<pair<int, int> > ans;
void Reverse(int l, int r) {
  ans.push_back(make_pair(l, r));
  for (int i = l; i <= (l + r) / 2; ++i) swap(s[i], s[l + r - i]);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      if (i % 2 && s[i] == ')') {
        int j = i + 1;
        while (s[j] == ')') ++j;
        Reverse(i, j);
      }
      if (i % 2 == 0 && s[i] == '(') {
        int j = i + 1;
        while (s[j] == '(') ++j;
        Reverse(i, j);
      }
    }
    if (k < n / 2) {
      int pos = (k - 1) * 2 + 1;
      ans.push_back(make_pair(pos + 1, n - 1));
    }
    printf("%d\n", ans.size());
    for (int i = 0; i != ans.size(); ++i)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
