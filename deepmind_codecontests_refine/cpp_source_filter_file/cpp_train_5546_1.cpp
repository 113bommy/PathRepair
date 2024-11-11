#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
void solve() {
  int m;
  cin >> m;
  vector<long long> pos, neg;
  long long ans = -LINF;
  for (int i = 0; i < m; i++) {
    long long a;
    cin >> a;
    if (a == 0)
      ans = 0;
    else if (a > 0)
      pos.push_back(a);
    else
      neg.push_back(a);
  }
  sort(pos.rbegin(), pos.rend());
  sort(neg.begin(), neg.end());
  for (int p = 0; p <= 5; p++) {
    int n = 5 - p;
    long long tmp = 1;
    if (p > pos.size() || n > neg.size()) continue;
    for (int k = 0; k < p; k++) tmp *= pos[k];
    for (int k = 0; k < n; k++) tmp *= neg[k];
    ans = max(ans, tmp);
  }
  reverse(pos.begin(), pos.end());
  reverse(neg.begin(), neg.end());
  for (int p = 0; p <= 5; p++) {
    int n = 5 - p;
    long long tmp = 1;
    if (p > pos.size() || n > neg.size()) continue;
    for (int k = 0; k < p; k++) tmp *= pos[k];
    for (int k = 0; k < n; k++) tmp *= neg[k];
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
