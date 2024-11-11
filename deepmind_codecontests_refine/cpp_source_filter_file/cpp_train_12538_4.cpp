#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MXN = 1e5 + 1;
int n;
int a[MXN], b[MXN], id[MXN], dp[MXN], p[MXN];
bool np[MXN];
vector<int> v;
int main() {
  np[1] = np[0] = 1;
  for (int i = 2; i < MXN; i++) {
    if (!np[i]) {
      if (i * 1LL * i < MXN)
        for (int j = i * i; j < MXN; j += i) np[j] = 1;
      v.push_back(i);
    }
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    id[a[i]] = i;
    b[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = INF;
    for (auto it : v) {
      if (i - it < 0) break;
      if (dp[i - it] + 1 < dp[i]) {
        dp[i] = dp[i - it] + 1;
        p[i] = it;
      }
    }
  }
  sort(b, b + n);
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    if (i + 1 == a[i]) continue;
    int j = id[i + 1];
    while (i < j) {
      int sw = j - p[j - i];
      swap(id[a[j]], id[a[sw]]);
      swap(a[j], a[sw]);
      v.push_back({sw + 1, j + 1});
      j = sw;
    }
  }
  printf("%d\n", (int)v.size());
  for (auto it : v) printf("%d %d\n", it.first, it.second);
  return 0;
}
