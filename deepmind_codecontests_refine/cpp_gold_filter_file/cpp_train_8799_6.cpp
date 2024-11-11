#include <bits/stdc++.h>
struct el {
  long long x, y;
};
using namespace std;
int main(int argc, const char* argv[]) {
  int n, m, k;
  cin >> n >> m >> k;
  int d[k + 1];
  for (int i = 0; i < k + 1; i++) {
    d[i] = 0;
  }
  int x;
  for (int i = 0; i < k; i++) {
    cin >> x;
    d[x] = i + 1;
  }
  int ans = 0;
  for (int t = 0; t < n; t++) {
    for (int i = 0; i < m; i++) {
      cin >> x;
      ans += d[x];
      for (int i = 1; i < k + 1; i++) {
        if (d[i] < d[x]) {
          d[i]++;
        }
      }
      d[x] = 1;
    }
  }
  cout << ans;
}
