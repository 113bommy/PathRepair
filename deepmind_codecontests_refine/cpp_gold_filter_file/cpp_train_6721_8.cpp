#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 7;
const int M = 1000 + 3;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * (inf - 1);
const double pi = acos(-1);
const double eps = 1e-6;
const bool multipleTest = false;
int n;
string s;
void solve() {
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == '<')
      ++ans;
    else
      break;
  for (int i = n - 1; i >= 0; --i)
    if (s[i] == '>')
      ++ans;
    else
      break;
  cout << ans;
}
void createTest() {
  freopen("in.txt", "w", stdout);
  cout << 1 << "\n";
  cout << 100000 << " " << 100000 << "\n";
  for (int i = 1; i <= 100000; ++i) {
    int u = rand();
    int v = rand();
    if (u > v) swap(u, v);
    printf("%d %d\n", u, v);
  }
  for (int i = 1; i <= 100000; ++i) {
    int u = rand();
    int v = rand();
    if (u > v) swap(u, v);
    printf("%d %d\n", u, v);
  }
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
