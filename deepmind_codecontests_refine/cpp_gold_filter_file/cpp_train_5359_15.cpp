#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m;
int b, g;
int d1[maxn], d2[maxn];
void Solve() {
  cin >> n >> m;
  cin >> b;
  for (int i = 1; i <= b; ++i) {
    int x;
    cin >> x;
    d1[x] = 1;
  }
  cin >> g;
  for (int i = 1; i <= g; ++i) {
    int x;
    cin >> x;
    d2[x] = 1;
  }
  for (int i = 0; i <= 10000; ++i) {
    int curb = i % n;
    int curg = i % m;
    if (d1[curb] || d2[curg]) d1[curb] = d2[curg] = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (!d1[i]) {
      cout << "No";
      return;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (!d2[i]) {
      cout << "No";
      return;
    }
  }
  cout << "Yes";
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  if (fopen("CF"
            ".inp",
            "r")) {
    freopen(
        "CF"
        ".inp",
        "r", stdin);
    freopen(
        "CF"
        ".out",
        "w", stdout);
  }
  int test = 1;
  while (test--) {
    Solve();
  }
}
