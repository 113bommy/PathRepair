#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100020;
int n, k;
unsigned long long tp[Maxn];
unsigned long long solve(int num, multiset<int>& S) {
  int cnt = 1;
  unsigned long long ret = 1ULL << 63;
  for (multiset<int>::iterator it = S.begin(); it != S.end(); cnt++, it++) {
    tp[cnt] = *it;
    if (cnt >= num) ret = min(ret, tp[cnt] - tp[cnt - num + 1]);
  }
  if (ret & 1) ret++;
  ret = max(ret, 2ULL);
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  vector<pair<int, int> > V;
  for (int i = 1; i <= n; i++) {
    int xx1, yy1, xx2, yy2;
    scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
    xx1 <<= 1, yy1 <<= 1, xx2 <<= 1, yy2 <<= 1;
    V.push_back(
        pair<int, int>(xx1 + ((xx2 - xx1) >> 1), yy1 + ((yy2 - yy1) >> 1)));
  }
  if (k == n - 1) {
    cout << 1 << endl;
    return 0;
  }
  multiset<int> S;
  unsigned long long ans = 1ULL << 63;
  sort(V.begin(), V.end());
  for (int i = 0; i < V.size(); i++) S.insert(V[i].second);
  for (int i = 0; i <= k; i++)
    for (int j = 0; j + i <= k; j++) {
      if (n - j - 1 < i) continue;
      int X = V[n - j - 1].first - V[i].first;
      if (X & 1) X++;
      X = max(X, 2);
      for (int p = 0; p < i; p++) S.erase(S.lower_bound(V[p].second));
      for (int p = n - j; p < V.size(); p++)
        S.erase(S.lower_bound(V[p].second));
      ans = min(ans, solve(n - k, S) * 1ULL * X);
      for (int p = 0; p < i; p++) S.insert(V[p].second);
      for (int p = n - j; p < V.size(); p++) S.insert(V[p].second);
    }
  cout << (ans >> 2) << endl;
}
