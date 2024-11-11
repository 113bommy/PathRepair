#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
long long a[mx];
long long b[mx];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n & 1) {
    cout << n / 2 << endl;
    int tmp = 0;
    for (int i = 1; i < n; i += 2) {
      b[i] = a[tmp++];
    }
    for (int i = 0; i < n; i += 2) {
      b[i] = a[tmp++];
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  } else {
    cout << (n - 1) / 2 << endl;
    n--;
    int tmp = 0;
    for (int i = 1; i < n; i += 2) {
      b[i] = a[tmp++];
    }
    for (int i = 0; i < n; i += 2) {
      b[i] = a[tmp++];
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << a[n - 1] << endl;
  }
}
