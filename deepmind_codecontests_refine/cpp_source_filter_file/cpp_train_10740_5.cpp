#include <bits/stdc++.h>
using namespace std;
const int MM = 320000;
const int LE = 1100000;
long long da[220000];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long b, q, w;
  cin >> q;
  while (q-- != 0) {
    cin >> b >> w;
    int off = 0, fi = 1, st = 0, ok = 1;
    int bx = 3, by = 2;
    vector<pair<int, int> > ans;
    if (b > w) swap(w, b), off = 1;
    while (b < w) {
      if (b == 0) {
        ok = 0;
        break;
      }
      b--;
      ans.push_back({bx, by});
      st = 1;
      by += 2;
      if (fi && b < w) w--, ans.push_back({bx, by - 2 - 1}), st = 1;
      if (b < w) w--, ans.push_back({bx, by - 2 + 1}), st = 0;
      if (b < w) w--, ans.push_back({bx + 1, by - 2});
      if (b < w) w--, ans.push_back({bx - 1, by - 2});
      fi = 0;
    }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    int nd = b + w;
    if (st == 1 && nd) nd--, ans.push_back({bx, by - 1});
    while (nd-- > 0) {
      ans.push_back({bx, ++by});
    }
    cout << "YES" << endl;
    for (auto pp : ans) {
      cout << pp.first + off << " " << pp.second << endl;
    }
  }
}
