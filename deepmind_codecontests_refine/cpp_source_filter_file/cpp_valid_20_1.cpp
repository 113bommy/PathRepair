#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2 + 14;
int n, k, a[MAX_N], b[MAX_N], c[MAX_N * MAX_N];
uint8_t blocked[MAX_N * MAX_N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n * k; ++i) {
    cin >> c[i];
    --c[i];
    if (!b[c[i]]) {
      int j = i - 1;
      while (j >= 0 && c[j] != c[i]) --j;
      if (j >= 0 &&
          *max_element(blocked + j, blocked + i) <= (n + k - 2) / (k - 1)) {
        a[c[i]] = j;
        b[c[i]] = i;
        while (j < i) ++blocked[j++];
      }
    }
  }
  assert(*min_element(b, b + n));
  for (int i = 0; i < n; ++i) cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
}
