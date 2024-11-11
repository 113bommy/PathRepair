#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100003];
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    a[i] = i;
    cout << i << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    b[i] = (i + 1) % n;
    cout << b[i] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << (a[i] + b[i]) % n << ' ';
  }
  return 0;
}
