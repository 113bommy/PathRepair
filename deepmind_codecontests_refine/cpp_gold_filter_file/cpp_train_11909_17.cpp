#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (!(n & 1)) {
    cout << "-1\n";
  } else {
    int a[n], b[n], c[n];
    for (int i = 0; i < (n); i++) {
      a[i] = i;
      b[i] = (i + 1) % n;
      c[i] = (a[i] + b[i]) % n;
    }
    for (int i = 0; i < (n); i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < (n); i++) cout << b[i] << " ";
    cout << "\n";
    for (int i = 0; i < (n); i++) cout << c[i] << " ";
    cout << "\n";
  }
  return 0;
}
