#include <bits/stdc++.h>
using namespace std;
struct Debug {
  int cnt = 0;
  bool on = false;
  char debug[10] = "debug";
  template <class T>
  Debug& operator<<(const T& v) {
    if (on && cnt++ == 0) cerr << "debug: ";
    if (on) cerr << v << ' ';
    return *this;
  }
  Debug& operator<<(ostream& (*pManip)(ostream&)) {
    if (on) cerr << (*pManip);
    cnt = 0;
    return *this;
  }
} debug;
const int MAXN = 1e6 + 10;
int n;
int a[MAXN];
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (argc > 1 && !strcmp(argv[1], debug.debug)) debug.on = true;
  cin >> n;
  for (auto i = (0); i < (n); i++) cin >> a[i];
  set<vector<int>, greater<vector<int>>> cur({{n + 1, 0, n}});
  vector<vector<int>> res(n + 1, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    auto tmp = *cur.begin();
    cur.erase(cur.begin());
    if (a[i] < tmp[0]) {
      for (auto j = (tmp[1]); j < (tmp[1] + a[i]); j++) res[j][i] = 1;
      cur.insert({{a[i], tmp[1], tmp[1] + a[i] - 1}});
      cur.insert({{tmp[2] - tmp[1] - a[i] + 1, tmp[1] + a[i], tmp[2]}});
    } else {
      for (auto j = (tmp[1]); j < (tmp[2]); j++) res[j][i] = 1;
      a[i] -= tmp[2] - tmp[1];
      for (auto j = (0); j < (n + 1); j++) {
        if (!a[i]) break;
        if (tmp[1] <= j && j <= tmp[2]) continue;
        res[j][i] = 1;
        --a[i];
      }
      cur.insert({tmp[0] - 1, tmp[1], tmp[2] - 1});
    }
  }
  int cnt = 0;
  for (auto i = (0); i < (n + 1); i++) {
    if (accumulate((res[i]).begin(), (res[i]).end(), 0) == 0) continue;
    cnt++;
  }
  cout << cnt << endl;
  for (auto i = (0); i < (n + 1); i++) {
    if (accumulate((res[i]).begin(), (res[i]).end(), 0) == 0) continue;
    for (auto j = (0); j < (n); j++) cout << res[i][j];
    cout << endl;
  }
  return 0;
}
