#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, L = 20;
long long s[N][L], p[N][L], m[N][L];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i][0];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i][0];
    m[i][0] = s[i][0];
  }
  for (int j = 1; j < L; j++) {
    for (int i = 0; i < n; i++) {
      p[i][j] = p[p[i][j - 1]][j - 1];
      s[i][j] = s[i][j - 1] + s[p[i][j - 1]][j - 1];
      m[i][j] = min(m[i][j - 1], m[p[i][j - 1]][j - 1]);
    }
  }
  for (int i = 0; i < n; i++) {
    long long sum = 0, mn = 1e18, u = i, x = k, c = 0;
    while (x > 0) {
      if (x & 1) {
        sum += s[u][c];
        mn = min(mn, m[u][c]);
        u = p[u][c];
      }
      x >>= 1;
      c++;
    }
    cout << sum << " " << mn << "\n";
  }
}
