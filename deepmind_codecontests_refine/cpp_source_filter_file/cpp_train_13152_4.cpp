#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int temp = 0;
  for (int i = 0; i * a <= n; i++) {
    for (int j = 0; j * b <= n; j++) {
      if ((n - (j * b + i * a)) % c == 0) {
        temp = max(temp, i + j + (n - (j * b + i * a)) / c);
      }
    }
  }
  cout << temp << endl;
  return 0;
}
