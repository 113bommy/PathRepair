#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100], b[100], c[100], s[100];
  bool B[10000] = {};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int w = 0; w < n; w++) {
      if (a[i] > a[w] && b[i] > b[w] && c[i] > c[w]) {
        B[w] = 1;
      }
    }
  }
  int MIN = 1001, index;
  for (int i = 0; i < n; i++) {
    if (!B[i]) {
      if (s[i] < MIN) {
        MIN = s[i];
        index = i + 1;
      }
    }
  }
  cout << index;
}
