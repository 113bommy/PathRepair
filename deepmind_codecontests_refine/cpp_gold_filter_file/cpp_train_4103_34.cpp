#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, sum = 0;
  cin >> n >> m >> k;
  int rand[1001];
  for (int i = 0; i < 1001; ++i) {
    rand[i] = 1 << 21;
  }
  for (int i = 0; i < n; i++) {
    int r, v;
    cin >> r >> v;
    rand[r] = min(rand[r], v);
  }
  for (int i = 1; i <= m; i++) {
    sum += rand[i];
  }
  if (sum > k) sum = k;
  cout << sum << endl;
}
