#include <bits/stdc++.h>
using namespace std;
string to_string(char s) { return string(1, s); }
string to_string(string s) { return "\"" + s + "\""; }
template <typename T>
string to_string(vector<T>);
template <typename U, typename V>
string to_string(pair<U, V> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename T>
string to_string(vector<T> v) {
  string res = "[";
  for (int i = 0; i < (int)v.size() - 1; i++) res += to_string(v[i]) + ", ";
  if (!v.empty()) res += to_string(v.back());
  res += "]";
  return res;
}
const int N = 300010;
char s[N];
int n, f[N], g[N];
int sa, sb;
int numSeg(int l, int r) {
  if (l > r) return 0;
  int sm = 0, ans = 0;
  for (int i = l; i <= r; i++) {
    sm += g[i];
    if (sm == 0) ans++;
  }
  return ans;
}
vector<pair<int, int> > findSeg(int l, int r) {
  vector<pair<int, int> > res;
  int ix = l, sm = 0;
  for (int i = l; i <= r; i++) {
    sm += g[i];
    if (sm == 0) {
      res.push_back({ix, i});
      ix = i + 1;
    }
  }
  return res;
}
bool isBalanced() {
  int sm = 0;
  for (int i = 0; i < n; i++) {
    sm += g[i];
    if (sm < 0) return false;
  }
  return (sm == 0);
}
int solve() {
  for (int i = 0; i < n; i++) f[i] = (s[i] == '(') ? 1 : -1;
  int sm = 0;
  for (int i = 0; i < n; i++) sm += f[i];
  sa = 1;
  sb = 1;
  if (sm) return 0;
  int k = -1;
  sm = 0;
  for (int i = 0; i < n; i++) {
    sm += f[i];
    if (sm == -1) {
      k = i;
      sm = 0;
    }
  };
  for (int i = 0; i < n; i++) g[i] = f[(k + i + 1) % n];
  assert(isBalanced());
  for (int i = 0; i < n; i++)
    ;
  vector<pair<int, int> > sg;
  sm = 0;
  int ix = 0;
  for (int i = 0; i < n; i++) {
    sm += g[i];
    if (sm == 0) {
      sg.push_back({ix, i});
      ix = i + 1;
    }
  };
  int mx = (int)sg.size();
  for (int i = 0; i < (int)sg.size(); i++) {
    int z = numSeg(sg[i].first + 1, sg[i].second - 1) + 1;
    ;
    ;
    if (z > mx) {
      mx = z;
      sa = sg[i].first;
      sb = sg[i].second;
      ;
      ;
      sa = (k + 1 + sa) % n + 1;
      sb = (k + 1 + sb) % n + 1;
    }
  }
  for (int i = 0; i < (int)sg.size(); i++) {
    vector<pair<int, int> > p = findSeg(sg[i].first + 1, sg[i].second - 1);
    if (p.empty()) continue;
    int maxi = numSeg(p[0].first + 1, p[0].second - 1), ixi = 0;
    for (int j = 1; j < (int)p.size(); j++) {
      int tmp = numSeg(p[j].first + 1, p[j].second - 1);
      if (tmp > maxi) {
        maxi = tmp;
        ixi = j;
      }
    };
    maxi += 1 + (int)sg.size();
    if (maxi > mx) {
      mx = maxi;
      sa = p[ixi].first;
      sb = p[ixi].second;
      sa = (k + 1 + sa) % n + 1;
      sb = (k + 1 + sb) % n + 1;
    }
  }
  return mx;
}
int main() {
  scanf("%d%s", &n, s);
  printf("%d\n", solve());
  printf("%d %d\n", sa, sb);
}
