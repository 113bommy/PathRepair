#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200200;
vector<int> at[NMAX];
long long p[NMAX], b[NMAX];
long long pi[NMAX];
int n, k;
bool check(long long m) {
  for (int i = 0; i <= k; ++i) {
    at[i] = vector<int>();
  }
  for (int i = 0; i < n; ++i) {
    p[i] = pi[i];
    long long v = p[i] / b[i];
    if (v < k) at[v].push_back(i);
  }
  int j = 0;
  for (int i = 0; i < k && j <= k; ++i) {
    while (at[j].size() == 0 && j <= k) ++j;
    if (j > k) return true;
    if (j < i) return false;
    int u = at[j].back();
    at[j].pop_back();
    p[u] += m;
    long long v = p[u] / b[u];
    if (v < k) at[v].push_back(u);
  }
  while (at[j].size() == 0 && j <= k) ++j;
  return true;
}
long long bs() {
  const long long TOP = 2000000000001LL;
  long long lo = 0, hi = TOP;
  while (lo < hi) {
    long long m = (lo + hi) / 2;
    if (check(m)) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  return (lo == TOP ? -1 : lo);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> pi[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  cout << bs() << endl;
  return 0;
}
