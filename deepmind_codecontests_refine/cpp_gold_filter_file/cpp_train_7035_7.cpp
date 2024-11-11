#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
vector<int> commands;
string t, p;
vector<bool> removed;
int lp, lt;
bool isSubSeq(int m) {
  for (int i = 0; i < m; i++) {
    removed[commands[i]] = true;
  }
  int i = 0, j = 0;
  while (i < lt && j < lp) {
    if (!removed[i + 1] && p[j] == t[i]) {
      j++;
    }
    i++;
  }
  return j == lp;
}
int binary(int l, int r) {
  int m;
  while (l < r) {
    m = (l + r) / 2;
    fill(removed.begin(), removed.end(), false);
    if (isSubSeq(m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return isSubSeq(m) ? m : m - 1;
}
int main() {
  cin >> t >> p;
  lp = p.length(), lt = t.length();
  removed.resize(lt + 1);
  int x;
  for (int i = 0; i < lt; i++) {
    cin >> x;
    commands.push_back(x);
  }
  cout << (binary(0, lt));
  return 0;
}
