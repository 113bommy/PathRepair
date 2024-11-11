#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
long long C[16000][551];
int main() {
  C[0][0] = 1;
  for (int i = 1; i < 16000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= min(i, 550); j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][j] %= 1000000007;
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 2; j <= sqrt(a); j++) {
      while (a % j == 0) {
        a /= j;
        m[j]++;
      }
    }
    if (a != 1) m[a]++;
  }
  long long ans = 1;
  for (map<int, int>::iterator i = m.begin(); i != m.end(); i++) {
    ans *= ans * C[i->second + n - 1][n - 1];
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
