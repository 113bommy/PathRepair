#include <bits/stdc++.h>
using namespace std;
pair<int, int> P[5000];
set<pair<int, int> > S;
int I[5000];
bool cmp(pair<int, int> A, pair<int, int> B) {
  if (A.first == B.first) return A.second < B.second;
  return A.first < B.first;
}
int main() {
  int n, m, a, b, res = INT_MAX;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    P[i].first = a;
    P[i].second = b;
    S.insert(P[i]);
    I[a]++;
    I[b]++;
  }
  sort(P + 1, P + m + 1, cmp);
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++)
      if (P[i].first == P[j].first) {
        if (S.find(make_pair(P[i].second, P[j].second)) != S.end()) {
          res = min(res, I[P[i].first] + I[P[i].second] + I[P[j].second] - 6);
        }
      } else {
        break;
      }
  }
  if (res == INT_MAX)
    cout << "-1";
  else
    cout << res;
}
