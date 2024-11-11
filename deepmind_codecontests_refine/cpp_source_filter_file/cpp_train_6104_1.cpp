#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 9;
const int shift = 1e3 + 9;
const double Eps = 1e-7;
const string a = "What are you doing while sending \"",
             b = "\"? Are you busy? Will you send \"", d = "\"?";
const string f1 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
long long l[N], k;
int q, n;
void pre() {
  l[1] = f1.length();
  for (int i = 2; i <= 60; i++)
    l[i] = a.length() + b.length() + d.length() + 2LL * l[i - 1];
  for (int i = 61; i < N; i++) l[i] = l[i - 1];
}
char dfs(int n, long long k) {
  if (n == 1) return k > f1.length() ? '.' : f1[k - 1];
  if (k <= a.length()) return a[k - 1];
  if (k <= a.length() + l[n - 1]) return dfs(n - 1, k - a.length());
  if (k <= a.length() + l[n - 1] + b.length())
    return b[k - a.length() - l[n - 1] - 1];
  if (k <= a.length() + l[n - 1] + b.length() + l[n - 1])
    return dfs(n - 1, k - a.length() - l[n - 1] - b.length());
  if (k <= a.length() + l[n - 1] + b.length() + l[n - 1] + d.length())
    return d[k - a.length() - l[n - 1] - b.length() - l[n - 1]];
  return '.';
}
int main(void) {
  if (fopen("in", "r") != NULL) {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  }
  pre();
  while (cin >> q) {
    while (q--) {
      cin >> n >> k;
      n++;
      cout << dfs(n, k);
    }
    cout << endl;
  }
  return 0;
}
