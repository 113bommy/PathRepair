#include <bits/stdc++.h>
using namespace std;
long long color[100005];
int32_t main() {
  long long n, m;
  long long a, b, c;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (color[a] == 0 && color[b] == 0 && color[c] == 0) {
      color[a] = 1;
      color[b] = 2;
      color[c] = 3;
    } else if (color[a]) {
      if (color[a] == 1) {
        color[b] = 2;
        color[c] = 3;
      } else if (color[a] == 2) {
        color[b] = 1;
        color[c] = 3;
      } else {
        color[b] = 1;
        color[c] = 2;
      }
    } else if (color[b]) {
      if (color[b] == 1) {
        color[a] = 2;
        color[c] = 3;
      } else if (color[b] == 2) {
        color[a] = 1;
        color[c] = 3;
      } else {
        color[a] = 1;
        color[c] = 2;
      }
    } else if (color[c]) {
      if (color[c] == 1) {
        color[b] = 2;
        color[a] = 3;
      } else if (color[c] == 2) {
        color[b] = 1;
        color[a] = 3;
      } else {
        color[b] = 1;
        color[a] = 2;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (color[i] == 0) cout << 1 << " ";
    cout << color[i] << " ";
  }
}
