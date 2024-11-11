#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int ans[maxn];
map<string, int> mp;
int main() {
  int n, a, b, k, f;
  scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
  string pre = "";
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int cost;
    if (pre == s1) {
      cost = b;
    } else {
      cost = a;
    }
    pre = s2;
    if (s1 > s2) swap(s1, s2);
    s1 += s2;
    mp[s1] += cost;
  }
  int cnt = 0;
  for (auto i : mp) {
    ans[cnt++] = i.second;
  }
  sort(ans, ans + cnt);
  int res = 0, c = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (ans[i] > f && c <= k) {
      res += f;
      c++;
    } else {
      res += ans[i];
    }
  }
  printf("%d\n", res);
}
