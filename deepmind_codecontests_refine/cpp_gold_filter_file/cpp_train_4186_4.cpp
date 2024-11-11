#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return "\"" + s + "\""; }
template <typename T>
string to_string(vector<T>);
template <typename U, typename V>
string to_string(pair<U, V> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename T>
string to_string(vector<T> v) {
  string r = "[";
  for (int i = 0; i < (int)v.size() - 1; i++) r += to_string(v[i]) + ", ";
  if (!v.empty()) r += to_string(v.back());
  return r + "]";
}
const int N = 1010;
char a[N];
int n;
int solve() {
  vector<int> ix;
  for (int i = 0; i < n; i++)
    if (a[i] == '1') ix.push_back(i);
  if (ix.empty()) return n;
  int g1 = ix.front(), g2 = n - 1 - ix.back();
  return max(n + (int)ix.size(), 2 * (max(g1, g2) + n - (g1 + g2)));
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    scanf("%s", a);
    printf("%d\n", solve());
  }
}
