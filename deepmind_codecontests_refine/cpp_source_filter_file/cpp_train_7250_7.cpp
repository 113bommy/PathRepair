#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7;
const int inf = (int)1e9;
const long long linf = (long long)1e18;
const long double pi = acos(-1.0);
const int prime = 748297;
inline void finclude() { srand(time(NULL)); }
struct po {
  int type;
  int i, j, k;
};
bool check[256];
vector<po> ans;
bool f(int depth, int cur_depth, vector<int>& a, int k) {
  if (depth == cur_depth) return false;
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int step = 1;
      for (;;) {
        if (step > 8) break;
        int cur = step * a[i] + a[j];
        step *= 2;
        if (cur > k) break;
        if (cur == k) {
          po help;
          help.type = 1;
          help.i = a[i];
          help.j = a[j];
          help.k = step / 2;
          ans.push_back(help);
          return true;
        }
        if (check[cur]) continue;
        check[cur] = true;
        a.push_back(cur);
        if (f(depth, cur_depth + 1, a, k)) {
          po help;
          help.type = 1;
          help.i = a[i];
          help.j = a[j];
          help.k = step / 2;
          ans.push_back(help);
          a.pop_back();
          return true;
        }
        a.pop_back();
        check[cur] = false;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int step = 2;
    for (;;) {
      if (step > 8) break;
      int cur = step * a[i];
      step *= 2;
      if (cur > k) break;
      if (cur == k) {
        po help;
        help.type = 2;
        help.i = a[i];
        help.k = step / 2;
        ans.push_back(help);
        return true;
      }
      if (check[cur]) continue;
      check[cur] = true;
      a.push_back(cur);
      if (f(depth, cur_depth + 1, a, k)) {
        po help;
        help.type = 2;
        help.i = a[i];
        help.k = step / 2;
        ans.push_back(help);
        return true;
      }
      a.pop_back();
      check[cur] = false;
    }
  }
  return false;
}
string next(string s) {
  ++s[1];
  return s;
}
int main() {
  finclude();
  int k;
  cin >> k;
  if (k == 1) {
    cout << "0\n";
    return 0;
  }
  map<int, string> m;
  m.insert(pair<int, string>(1, "eax"));
  vector<int> a(0);
  a.push_back(1);
  map<int, string>::iterator fi, se;
  for (int i = 1;; ++i) {
    if (f(i, 0, a, k)) {
      cout << i << '\n';
      string cur = "eax";
      for (int j = i - 1; j >= 0; --j) {
        if (ans[j].type == 1) {
          fi = m.find(ans[j].i);
          se = m.find(ans[j].j);
          cur = next(cur);
          if (ans[j].k > 1)
            cout << "lea " << cur << ", [" << se->second << " + " << ans[j].k
                 << "*" << fi->second << "]\n";
          else
            cout << "lea " << cur << ", [" << se->second << " + " << fi->second
                 << "]\n";
          int x = ans[j].i * ans[j].k + ans[j].j;
          m.insert(pair<int, string>(x, cur));
        } else {
          fi = m.find(ans[j].i);
          cur = next(cur);
          cout << "lea " << cur << ", [" << ans[j].k << "*" << fi->second
               << "]\n";
          m.insert(pair<int, string>(ans[j].i * k, cur));
        }
      }
      return 0;
    }
  }
}
