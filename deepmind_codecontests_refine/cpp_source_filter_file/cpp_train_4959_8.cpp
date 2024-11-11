#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int vet[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> vet[i];
  }
  int f = 1;
  for (int i = 1; i < n; i++) {
    if (vet[i] % vet[0]) {
      cout << -1 << endl;
      f = 0;
      break;
    }
  }
  if (f) {
    cout << 2 * n << endl;
    for (int i = 0; i < n; i++) {
      if (i) {
        cout << " ";
      }
      cout << vet[0] << " " << vet[1];
    }
    cout << endl;
  }
  return 0;
}
