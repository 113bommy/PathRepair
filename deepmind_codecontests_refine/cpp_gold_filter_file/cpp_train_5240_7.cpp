#include <bits/stdc++.h>
using namespace std;
int main() {
  bool b[200100] = {0};
  vector<int> v[26];
  int n, q, r;
  char c;
  string s, t;
  cin >> n >> s >> q;
  for (int i = 0; i < n; ++i) t += s;
  for (int i = 0; i < t.size(); ++i) v[t[i] - 'a'].push_back(i);
  for (int i = 0; i < q; ++i) {
    cin >> r >> c;
    b[v[c - 'a'][r - 1]] = 1;
    v[c - 'a'].erase(v[c - 'a'].begin() + r - 1);
  }
  for (int i = 0; i < t.size(); ++i)
    if (!b[i]) cout << t[i];
  return 0;
}
