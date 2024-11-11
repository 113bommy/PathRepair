#include <bits/stdc++.h>
using namespace std;
template <class T>
void maximize(T &x, T y) {
  if (x < y) x = y;
}
template <class T>
void minimize(T &x, T y) {
  if (x > y) x = y;
}
string s;
vector<vector<int> > a(532000);
int len[532000];
map<pair<int, int>, int> pre_ans;
int get_hash(string &t) {
  int cur = 0;
  for (int i = 0; t[i] != '\0'; i++) {
    cur *= 27;
    cur += t[i] - 'a' + 1;
  }
  return cur;
}
int cal(int fihash, int sehash) {
  int res = 1e9;
  int it = 0;
  for (int i = 0; i < a[fihash].size(); i++) {
    while (it < int(a[sehash].size()) - 1 && a[sehash][it] < a[fihash][i]) {
      it++;
    }
    if (a[sehash][it] < a[fihash][i]) break;
    minimize(res, max(len[fihash], a[sehash][it] - a[fihash][i] + len[sehash]));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  for (int i = 0; s[i] != '\0'; i++) {
    int cur = 0;
    for (int j = 0; s[i + j] != '\0'; j++) {
      if (j >= 4) break;
      cur *= 27;
      cur += s[i + j] - 'a' + 1;
      a[cur].push_back(i);
      len[cur] = j + 1;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string x, y;
    cin >> x >> y;
    int fihash = get_hash(x);
    int sehash = get_hash(y);
    if (a[fihash].size() == 0 || a[sehash].size() == 0) {
      cout << "-1" << '\n';
      continue;
    }
    if (fihash > sehash) swap(fihash, sehash);
    if (pre_ans[make_pair(fihash, sehash)] != 0) {
      cout << pre_ans[make_pair(fihash, sehash)] << '\n';
      continue;
    }
    int res = 1e9;
    minimize(res, cal(fihash, sehash));
    minimize(res, cal(sehash, fihash));
    cout << res << '\n';
    pre_ans[make_pair(fihash, sehash)] = res;
  }
}
