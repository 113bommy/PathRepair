#include <bits/stdc++.h>
using namespace std;
const int mn = 5e5 + 5;
int n, m, k, s;
int a[mn];
int b[mn];
int doner[mn];
unordered_set<int> wait;
int cnt[mn];
int need[mn];
vector<int> ans;
void getin(int l, int r) {
  set<int> noterasepos;
  unordered_multiset<int> h;
  for (int i = 1; i <= s; i++) {
    h.insert(b[i]);
  }
  for (int i = l; i <= r; i++) {
    if (h.count(a[i])) {
      auto u = h.find(a[i]);
      h.erase(u);
      noterasepos.insert(i);
    }
  }
  int u = r - l + 1 - k;
  for (int i = l; i <= r && u; i++) {
    if (noterasepos.count(i))
      continue;
    else
      u--, ans.push_back(i);
  }
}
int main() {
  scanf("%d%d%d%d", &n, &k, &m, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= s; i++)
    scanf("%d", &b[i]), need[b[i]]++, wait.insert(b[i]);
  int r = 0;
  bool cando = 0;
  for (int i = 1; i <= n; i++) {
    while (!wait.empty() && r < n) {
      ++r;
      cnt[a[r]]++;
      if (wait.count(a[r]) && cnt[a[r]] >= need[a[r]]) {
        wait.erase(a[r]);
      }
    }
    if (r == n && !wait.empty()) {
      break;
    }
    doner[i] = r;
    if ((i - 1) / k + 1 + (n - r) / k >= m) {
      getin((i - 1) - (i - 1) % k + 1, r + (n - r) % k);
      int l = 0;
      while ((i - 1) / k - l >= m) {
        for (int j = l * k + 1; j <= (l + 1) * k; j++) ans.push_back(j);
        l++;
      }
      cando = 1;
      break;
    }
    cnt[a[i]]--;
    if (cnt[a[i]] < need[a[i]]) {
      wait.insert(a[i]);
    }
  }
  if (!cando)
    puts("-1");
  else {
    printf("%d\n", ((int)ans.size()));
    sort(ans.begin(), ans.end());
    for (auto &i : ans) {
      printf("%d ", i);
    }
  }
  return 0;
}
