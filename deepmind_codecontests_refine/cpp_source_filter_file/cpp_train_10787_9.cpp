#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> P[200010];
int v[200010];
pair<int, int> T[200010][50];
int m[200010][50];
vector<int> V;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) {
    while (!V.empty() && v[V.back()] < v[i])
      P[V.back()].second = i - 1, V.pop_back();
    P[i].second = n;
    if (V.empty())
      P[i].first = 1;
    else
      P[i].first = V.back() + 1;
    V.push_back(i);
  }
  for (int i = 1; i <= n; i++)
    for (int h = 0; h <= 30; h++)
      if ((v[i] & (1 << h))) m[i][h] = 1;
  for (int i = 0; i <= 30; i++)
    for (int h = 1; h <= n; h++) {
      int j = h;
      while (j <= n && m[h][i] == m[j][i]) j++;
      for (int k = h; k < j; k++) T[k][i] = {h, j - 1};
      h = j - 1;
    }
  long long ans = n * 1LL * (n + 1) / 2;
  for (int i = 1; i <= n; i++) {
    int l = P[i].first, r = P[i].second;
    for (int h = 0; h <= 30; h++) {
      if (m[i][h] == 1) continue;
      l = max(l, T[i][h].first);
      r = min(r, T[i][h].second);
    }
    ans -= (r - i + 1) * (i - l + 1);
  }
  printf("%d", ans);
}
