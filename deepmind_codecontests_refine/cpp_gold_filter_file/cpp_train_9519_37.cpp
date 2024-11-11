#include <bits/stdc++.h>
using namespace std;
int n, m, k, c, d;
int main() {
  cin >> c >> d;
  cin >> n >> m;
  cin >> k;
  int cnt = n * m - k;
  int min = 1e9;
  for (int i = 0; i <= 10000; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (n * i + j >= cnt) {
        if (i * c + j * d < min) {
          min = i * c + j * d;
        }
      }
    }
  }
  cout << min;
  return 0;
}
