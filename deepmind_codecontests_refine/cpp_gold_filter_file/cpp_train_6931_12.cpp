#include <bits/stdc++.h>
using namespace std;
void Primefact(int n) {
  bool arr[n + 1];
  memset(arr, true, sizeof(arr));
  for (int p = 2; p * p <= n + 1; p++) {
    if (arr[p] == true) {
      for (int i = p * p; i <= n + 1; i = i + p) {
        arr[i] = false;
      }
    }
  }
  for (int i = 2; i <= n + 1; i++) {
    if (arr[i]) {
      cout << 2 << "\n";
    } else {
      cout << "1"
           << "\n";
    }
  }
}
int main() {
  int n;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << "1" << endl << "1" << endl;
    if (n == 2) {
      cout << "1";
    }
  } else {
    cout << "2"
         << "\n";
  }
  if (n > 2) {
    Primefact(n);
  }
  return 0;
}
