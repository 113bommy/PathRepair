#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (; j < n - 1 - i; j++) {
      cout << 0 << " ";
    }
    if (j == n - 1 - i) {
      cout << k << " ";
      j++;
    }
    for (; j < n; j++) {
      cout << 0 << " ";
    }
    cout << endl;
  }
}
