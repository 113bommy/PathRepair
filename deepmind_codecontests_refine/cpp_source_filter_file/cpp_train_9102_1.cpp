#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100000 + 1;
const long long INF = 1e12;
int n, m;
const int MOD = 1000000007;
vector<char> p(MAXN, 1), used(MAXN, 0);
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &n);
  p[0] = p[1] = 0;
  for (int i = 2; i <= n; i++)
    if (p[i]) {
      if (i * 1ll * i <= n)
        for (int j = i * i; j <= n; j += n) p[j] = 0;
    }
  for (int i = n; i >= 2; i--) {
    if (!p[i]) continue;
    vector<int> a;
    for (int j = i; j <= n; j += i) {
      if (!used[j]) a.push_back(j);
    }
    if (a.size() < 2) continue;
    if (a.size() % 2 == 0) {
      for (int k = 0; k < a.size(); k += 2) {
        ans.push_back(pair<int, int>(a[k], a[k + 1]));
        used[a[k]] = used[a[k + 1]] = 1;
      }
    } else {
      ans.push_back(pair<int, int>(a[0], a[2]));
      used[a[0]] = used[a[2]] = 1;
      for (int k = 3; k < a.size(); k += 2) {
        ans.push_back(pair<int, int>(a[k], a[k + 1]));
        used[a[k]] = used[a[k + 1]] = 1;
      }
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
