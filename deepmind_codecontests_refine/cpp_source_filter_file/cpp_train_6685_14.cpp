#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
int main() {
  int t;
  cin >> t;
  vector<int> ans(t);
  vector<int> a;
  for (int i = 0; i < (int)t; i++) {
    int n;
    cin >> n;
    a.clear();
    int l[n], r[n];
    set<int> s;
    for (int j = 0; j < (int)n; j++) {
      cin >> l[j] >> r[j];
      if (s.find(l[j]) == s.end()) a.push_back(l[j]);
      s.insert(l[j]);
      if (s.find(r[j]) == s.end()) a.push_back(r[j]);
      s.insert(r[j]);
    }
    sort(a.begin(), a.end());
    int v = s.size();
    map<int, int> m;
    for (int j = 0; j < (int)v; j++) m[a[j]] = j * 2 + 1;
    vector<int> seg(2 * v + 1, 0);
    vector<int> one(2 * v + 1, 0);
    for (int j = 0; j < (int)n; j++) {
      seg[m[l[j]]]++;
      seg[m[r[j]] + 1]--;
    }
    for (int j = 1; j <= 2 * v; j++) seg[j] += seg[j - 1];
    int p = 1;
    for (int j = 1; j < 2 * v; j++) {
      if (seg[j] == 0) p++;
    }
    for (int j = 1; j <= 2 * v; j++) {
      one[j] += one[j - 1];
      if (j % 2 == 0 && seg[j] == 1) one[j]++;
    }
    int b = -INF;
    for (int j = 0; j < (int)n; j++) {
      int dif = one[m[r[j]]] - one[m[l[j]]];
      if (seg[m[r[j]] + 1] == 0 && seg[m[r[j]]] == 1 && seg[m[r[j]] - 1] == 1)
        dif--;
      if (seg[m[l[j]] - 1] == 0 && seg[m[l[j]]] == 1 && seg[m[l[j]] + 1] == 1)
        dif--;
      if (r[j] == l[j] && seg[m[r[j]] == 2 && seg[r[j]] + 1] == 0 &&
          seg[l[j] - 1] == 0)
        dif--;
      b = max(b, dif);
    }
    ans[i] = p + b;
  }
  for (auto k : ans) cout << k << endl;
  return 0;
}
