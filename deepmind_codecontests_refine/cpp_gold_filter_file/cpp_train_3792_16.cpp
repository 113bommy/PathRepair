#include <bits/stdc++.h>
using namespace std;
long long s[20001][2];
int main() {
  int n;
  cin >> n;
  for (size_t i = 0; i < 20001; i++) {
    s[i][0] = 0;
    s[i][1] = 0;
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (size_t j = 0; j < 20001; j++) {
      s[j][i % 2] = 0;
    }
    for (int j = 0; j < 20001; j++) {
      if (j + a < 20001) {
        s[j + a][i % 2] += s[j][(i + 1) % 2];
        s[j + a][i % 2] %= 1000000007;
      }
      if (j - a >= 0) {
        s[j - a][i % 2] += s[j][(i + 1) % 2];
        s[j - a][i % 2] %= 1000000007;
      }
      if (j == a + 10000 || j == 10000 - a) {
        s[j][i % 2]++;
        s[j][i % 2] %= 1000000007;
      }
    }
    sum += s[10000][i % 2];
    sum %= 1000000007;
  }
  cout << sum;
}
