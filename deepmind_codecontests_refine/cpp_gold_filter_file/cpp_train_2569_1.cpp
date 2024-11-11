#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010];
vector<int> vec[200010];
int cnt[200010];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i) vec[i].clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      ++cnt[a[i] % m];
      vec[a[i] % m].push_back(i);
    }
    int need = n / m;
    queue<int> q;
    long long res = 0;
    for (int i = 0; i < m; ++i) {
      while (!q.empty() && cnt[i] < need) {
        int top = q.front();
        q.pop();
        ++cnt[i];
        int add = i - (a[top] % m);
        res += add;
        a[top] += add;
      }
      while (cnt[i] > need) {
        q.push(*vec[i].rbegin());
        vec[i].pop_back();
        --cnt[i];
      }
    }
    for (int i = 0; i < m; ++i) {
      while (!q.empty() && cnt[i] < need) {
        int top = q.front();
        q.pop();
        ++cnt[i];
        int add = i + m - (a[top] % m);
        res += add;
        a[top] += add;
      }
    }
    printf("%lld\n", res);
    for (int i = 1; i <= n; ++i) printf("%lld%c", a[i], " \n"[i == n]);
  }
  return 0;
}
