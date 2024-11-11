#include <bits/stdc++.h>
using namespace std;
int n, s, e;
int x[5001];
int a[5001];
int b[5001];
int c[5001];
int d[5001];
inline long long cost(int i, int j) {
  if (i < j) return 1LL * abs(x[i] - x[j]) + d[i] + a[j];
  return 1LL * abs(x[i] - x[j]) + c[i] + b[j];
}
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> s >> e;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) cin >> d[i];
  v.push_back(s);
  v.push_back(e);
  for (int i = 1; i <= n; i++) {
    if (i == s || i == e) continue;
    int bpos = 1;
    long long bp = cost(v[0], i) + cost(i, v[1]) - cost(v[0], v[1]);
    for (int j = 2; j <= ((int)(v).size()) - 1; j++) {
      long long cp = cost(v[j - 1], i) + cost(v[j], i) - cost(v[j - 1], v[j]);
      if (cp < bp) {
        bpos = j;
        bp = cp;
      }
    }
    v.insert(v.begin() + bpos, i);
  }
  long long sol = 0;
  for (int i = 1; i <= n - 1; i++) sol += cost(v[i - 1], v[i]);
  cout << sol;
}
