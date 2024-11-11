#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 1e9;
inline void STDIO() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
string s[105];
long long w[105] = {}, h[105] = {};
int type[105] = {};
int sp[105] = {}, br[105] = {};
int kol[105];
vector<int> child[105];
bool use[105] = {};
void dfs(int i) {
  use[i] = 1;
  if (type[i] == 0) return;
  for (int j = 0; j < kol[i]; ++j)
    if (!use[child[i][j]]) dfs(child[i][j]);
  if (type[i] == 1) {
    if (kol[i] != 0) {
      for (int j = 0; j < kol[i]; ++j) {
        w[i] += w[child[i][j]] + sp[i];
        h[i] = max(h[i], h[child[i][j]]);
      }
      w[i] += 2 * br[i] - sp[i];
      h[i] += 2 * br[i];
    }
  }
  if (type[i] == -1) {
    if (kol[i] != 0) {
      for (int j = 0; j < kol[i]; ++j) {
        h[i] += h[child[i][j]] + sp[i];
        w[i] = max(w[i], w[child[i][j]]);
      }
      w[i] += 2 * br[i];
      h[i] += 2 * br[i] - sp[i];
    }
  }
}
int main() {
  int n;
  cin >> n;
  int k = 0;
  string c;
  char str[105];
  cin.getline(str, 105);
  for (int i = 0; i < n; ++i) {
    cin.getline(str, 105);
    c = str;
    int t = c.find(' ');
    if (t != string::npos) {
      if (c.substr(0, t) == "Widget") {
        int p = c.find('(');
        s[++k] = c.substr(t + 1, p - t - 1);
        ++p;
        while (c[p] != ',') {
          w[k] = 10 * w[k] + c[p] - '0';
          ++p;
        }
        ++p;
        while (c[p] != ')') {
          h[k] = 10 * h[k] + c[p] - '0';
          ++p;
        }
      } else if (c.substr(0, t) == "HBox") {
        s[++k] = c.substr(t + 1, c.length() - t);
        type[k] = 1;
      } else if (c.substr(0, t) == "VBox") {
        s[++k] = c.substr(t + 1, c.length() - t);
        type[k] = -1;
      }
    } else {
      int t = c.find('.');
      string name = c.substr(0, t);
      int ind;
      for (int i = 1; i <= k; ++i)
        if (s[i] == name) ind = i;
      int p = c.find('(');
      name = c.substr(t + 1, p - t - 1);
      if (name == "set_border") {
        ++p;
        br[ind] = 0;
        while (c[p] != ')') {
          br[ind] = 10 * br[ind] + c[p] - '0';
          ++p;
        }
      }
      if (name == "set_spacing") {
        ++p;
        sp[ind] = 0;
        while (c[p] != ')') {
          sp[ind] = 10 * sp[ind] + c[p] - '0';
          ++p;
        }
      }
      if (name == "pack") {
        ++kol[ind];
        name = c.substr(p + 1, c.length() - p - 2);
        int index;
        for (int i = 1; i <= k; ++i)
          if (name == s[i]) index = i;
        child[ind].push_back(index);
      }
    }
  }
  for (int i = 1; i <= k; ++i)
    if (!use[i]) dfs(i);
  for (int i = 1; i <= k; ++i)
    for (int j = i + 1; j <= k; ++j)
      if (s[j] < s[i]) {
        swap(s[i], s[j]);
        swap(w[i], w[j]);
        swap(h[i], h[j]);
      }
  for (int i = 1; i <= k; ++i)
    cout << s[i] << ' ' << w[i] << ' ' << h[i] << '\n';
}
