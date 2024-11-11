#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const int N = 1000 + 10, K = 1000 + 10;
const long long mod = 1000000007;
int n, k;
vector<int> ans;
void sol() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a > b) swap(a, b);
  n = (b - a) * 2;
  if (b >= n) {
    printf("-1\n");
    return;
  }
  if (c <= n / 2) {
    printf("%d\n", c + n / 2);
  } else
    printf("%d\n", c - n / 2);
}
void clear() {}
void once() {}
void solve() {
  int T;
  scanf("%d", &T);
  once();
  for (int i = 1; i <= (int)(T); ++i) {
    clear();
    sol();
  }
}
int main() {
  cout << fixed;
  cout.precision(10);
  cerr << fixed;
  cerr.precision(3);
  solve();
  return 0;
}
