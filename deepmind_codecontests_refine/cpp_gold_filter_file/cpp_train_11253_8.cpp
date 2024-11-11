#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int m = 1e9, n = 1e9;
int x, y;
int main() {
  int n, N, cnt = 0;
  cin >> n;
  N = sqrt(n);
  for (int i = 1; i <= N + 2; i++) {
    for (int j = 0; j < N; j++) {
      if (i * N - j <= n) cout << i * N - j << " ";
    }
  }
  cout << endl;
  return 0;
}
