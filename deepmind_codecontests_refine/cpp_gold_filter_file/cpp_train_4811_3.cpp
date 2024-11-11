#include <bits/stdc++.h>
using namespace std;
string a, b;
int n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> a;
  b.resize(n);
  for (int i = 0; i < k; i++) {
    b[i] = a[i];
    for (int j = 1; i + j * k < n; j++) b[i + j * k] = a[i];
  }
  if (b >= a) {
    cout << n << "\n" << b;
    return 0;
  }
  for (int i = k - 1; i >= 0; i--) {
    if (b[i] != '9') {
      b[i]++;
      for (int j = 1; i + j * k < n; j++) b[i + j * k] = b[i];
      break;
    } else {
      b[i] = '0';
    }
  }
  for (int i = 0; i < k; i++)
    for (int j = 1; i + j * k < n; j++) b[i + j * k] = b[i];
  cout << n << "\n" << b;
  return 0;
}
