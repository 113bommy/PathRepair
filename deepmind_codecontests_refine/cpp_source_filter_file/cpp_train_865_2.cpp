#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m, c, *first, *second, shag = 0;
  long *summ, buf;
  cin >> n >> m >> c;
  first = new long[n];
  second = new long[m];
  summ = new long[m];
  for (int i = 0; i < n; i++) {
    cin >> first[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> second[i];
  }
  if (n > 4) return 0;
  shag = 0;
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < m; j++) {
      first[i + j] += second[j];
      first[i + j] = first[i + j] % c;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << first[i] << ' ';
  }
  return 0;
}
