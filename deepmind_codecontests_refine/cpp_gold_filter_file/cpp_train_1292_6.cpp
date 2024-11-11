#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000, inf = ~0U >> 1;
int p[maxn], cnt = 0;
void init() {
  for (int i = 2; i < maxn; i++) {
    if (!p[i]) p[cnt++] = i;
    for (int j = 0; j < cnt && p[j] * i < maxn; j++) {
      p[p[j] * i] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int k;
int has[maxn];
vector<int> ans;
void ok() {
  if (ans.size() == k) {
    for (__typeof(ans.begin()) it = ans.begin(); it != ans.end(); it++)
      cout << *it << " ";
    exit(0);
  }
}
int main() {
  init();
  cin >> k;
  int range = 2 * k * k, req = (k + 1) / 2;
  for (int i = 0; ans.size() < k; i++) {
    int now = p[i];
    ans.push_back(now);
    for (int j = 0, len = ans.size(); j < ans.size(); j++)
      if (now * ans[j] <= range) ans.push_back(now * ans[j]);
  }
  for (int i = ans.size() - k; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
