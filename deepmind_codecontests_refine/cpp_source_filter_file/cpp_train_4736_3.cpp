#include <bits/stdc++.h>
using namespace std;
int const MAX_N = 370;
int const INF = 1e9;
int n, k, m, d[MAX_N];
bool c[MAX_N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    c[x] = true;
  }
  d[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (c[i]) {
      d[i] = 1;
    } else {
      bool ok = false;
      for (int j = i - 1; j >= 0 && j + k > i; --j)
        if (d[j] == 1) ok = true;
      if (!ok) d[i] = 1;
    }
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) answer += d[i];
  cout << answer << endl;
  return 0;
}
