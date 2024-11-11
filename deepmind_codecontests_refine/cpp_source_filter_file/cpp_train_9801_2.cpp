#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<int> a, q;
int main(int argc, char *argv[]) {
  cin >> n;
  vector<int> pref(n, 0);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  q.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> q[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  pref[0] = a[0];
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + a[i];
  }
  for (int c : q) {
    int cost = pref[c - 2];
    cost += pref[n - 1] - pref[c - 1];
    cout << cost << endl;
  }
  return 0;
}
