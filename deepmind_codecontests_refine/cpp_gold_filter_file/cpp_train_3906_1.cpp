#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n, s;
int frq[1002];
int t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    frq[a] = max(frq[a], b);
  }
  for (int i = s; i >= 0; --i) {
    t = max(t, frq[i]);
    if (i != 0) ++t;
  }
  cout << t;
  return 0;
}
