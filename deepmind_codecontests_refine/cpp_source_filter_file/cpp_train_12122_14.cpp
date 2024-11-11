#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, po = 0, temp;
  cin >> n >> c;
  int ex = n;
  int *ar = new int[c];
  int *aro = new int[n];
  for (int i = 0; i < c; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < c; i++) {
    while (ar[i] <= ex) {
      aro[po] = ar[i];
      ex--;
      po++;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int y = i + 1; y < n; y++) {
      if (aro[i] > aro[y]) {
        temp = aro[i];
        aro[i] = aro[y];
        aro[y] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << aro[i];
  }
}
