#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, c = 0;
  cin >> n >> k;
  map<char, int> m;
  for (int i = 97; i <= 122; i++) m[char(i)] = 0;
  m['f'] = 1;
  m['a'] = 20;
  m['c'] = 300;
  m['e'] = 4000;
  char a[n][k];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) cin >> a[i][j];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < k; j++) {
      int sum =
          m[a[i][j]] + m[a[i + 1][j]] + m[a[i][j + 1]] + m[a[i + 1][j + 1]];
      if (sum == 4321) {
        c++;
      }
    }
  }
  cout << c;
  return 0;
}
