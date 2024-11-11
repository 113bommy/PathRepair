#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
int n;
int pos[200001];
vector<int> b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    pos[a] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    pos[a] = i;
    b.push_back(a);
  }
  bool c = true;
  int f = b.back();
  int t = b.back();
  for (int i = n - 1; i >= 0 && t; i--, t--)
    if (b[i] != t) c = false;
  if (c) {
    for (int i = f + 1; i <= n; i++)
      if (pos[i] - i > 0) c = false;
    if (c) {
      cout << n - f;
      return 0;
    }
  }
  int maxx = -1e9;
  for (int i = 1; i <= n; i++) maxx = max(maxx, pos[i] - i);
  if (maxx >= 0)
    cout << min(2 * n, maxx + n + 1);
  else
    cout << 2 * n;
  return 0;
}
