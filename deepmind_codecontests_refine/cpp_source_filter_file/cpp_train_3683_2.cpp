#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100010] = {};
long long fans = 0;
vector<long long> p[100010];
bool cmp(long long x, long long y) { return x < y; }
vector<long long> mi;
vector<long long> ans;
unordered_map<long long, int> ha;
int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i]--;
  }
  sort(a + 1, a + n + 1, cmp);
  long long w;
  for (int i = 1; i <= 1; i++) {
    for (long long j = 1; j * j <= a[i]; j += 2) {
      if (a[i] % j != 0) continue;
      w = a[i] / j;
      p[i].push_back(j);
      if (j != w) {
        p[i].push_back(w);
      }
    }
    sort(p[i].begin(), p[i].end(), cmp);
  }
  for (int i = 0; i < p[1].size(); i++)
    mi.push_back(p[1][i]), ans.push_back(p[1][i]);
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) continue;
    mi.clear();
    for (int j = 0; j < ans.size(); j++) {
      if (a[i] % ans[j] == 0) {
        mi.push_back(ans[j]);
      }
    }
    ans.clear();
    for (int j = 0; j < mi.size(); j++) ans.push_back(mi[j]);
  }
  for (int i = 0; i < ans.size(); i++) {
    ha[ans[i]] = 1;
  }
  for (int i = 0; i < ans.size(); i++) {
    long long t = ans[i] << 1;
    if (t < m) {
      if (ha.find(t) == ha.end()) {
        ha[t] = 1;
        ans.push_back(t);
      }
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    fans += m - ans[i];
  }
  cout << fans << endl;
  return 0;
}
