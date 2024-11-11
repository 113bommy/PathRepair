#include <bits/stdc++.h>
using namespace std;
long long N[111];
int main() {
  long long n, sum = 0, x = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> N[i];
    sum += N[i];
  }
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 2) {
    if (N[0] == N[1])
      cout << -1 << endl;
    else {
      cout << 1 << endl;
      cout << 1 << endl;
    }
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    x += N[i];
    if (x != sum) {
      cout << i + 1 << endl;
      for (int j = 0; j <= i; j++) {
        cout << j + 1 << " \n"[j == i];
      }
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
