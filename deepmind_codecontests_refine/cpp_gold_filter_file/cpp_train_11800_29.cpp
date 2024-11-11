#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int prime = 9241;
const long double pi = acos(-1.);
int lcp[105][105];
string s[105];
int clcp(const string &a, const string &b) {
  for (int i = 0; i < min(a.length(), b.length()); i++)
    if (a[i] != b[i]) return i;
  return min(a.length(), b.length());
}
int curans = 0;
int bestans = 0;
int curcnt = 0;
int n, k;
int values[105];
void gen(int i) {
  if (curcnt + (n - i) < k || curcnt >= k) return;
  int may = curans;
  for (int j = i; j < n; j++) {
    for (int p = 0; p < curcnt; p++) may += lcp[j][values[p]];
    for (int p = i; p < j; p++) may += lcp[j][p];
  }
  if (may <= bestans) return;
  int was = curans;
  for (int j = 0; j < curcnt; j++) curans += lcp[i][values[j]];
  values[curcnt++] = i;
  bestans = max(curans, bestans);
  gen(i + 1);
  curcnt--;
  curans = was;
  gen(i + 1);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) lcp[i][j] = lcp[j][i] = clcp(s[i], s[j]);
  gen(0);
  cout << bestans << endl;
}
