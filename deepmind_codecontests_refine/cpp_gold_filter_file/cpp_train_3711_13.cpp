#include <bits/stdc++.h>
using namespace std;
int last_set_bit(long long int a) {
  int k = -1;
  while (a) {
    k++;
    a >>= 1;
  }
  return k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long int> b(n);
  vector<map<long long int, int> > d(60);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    int k = last_set_bit(b[i]);
    d[k][b[i]]++;
  }
  long long int a = -1;
  for (int i = 0; i < 60; ++i) {
    if (d[i].size()) {
      a = d[i].begin()->first;
      d[i][a]--;
      if (d[i][a] == 0) {
        d[i].erase(a);
      }
      break;
    }
  }
  assert(a > 0);
  vector<long long int> ans(n, a);
  for (int i = 1; i < n; ++i) {
    bool changed = 0;
    for (int j = 0; j < 60; ++j) {
      if (d[j].empty() || (a & (1ll << j))) {
        continue;
      }
      long long int t = d[j].begin()->first;
      d[j][t]--;
      if (d[j][t] == 0) {
        d[j].erase(t);
      }
      a ^= t;
      ans[i] = t;
      changed = 1;
      break;
    }
    if (!changed) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << ' ';
    }
    cout << ans[i];
  }
  return 0;
}
