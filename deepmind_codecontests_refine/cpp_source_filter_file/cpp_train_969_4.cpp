#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, amazing = 0;
  bool less = true, greater = true;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    less = true;
    greater = true;
    for (int j = i - 1; j < i && j >= 0; j--) {
      if (c[i] > c[j]) {
        less = false;
        break;
      }
    }
    for (int j = i - 1; j < i && j >= 0; j--) {
      if (c[i] <= c[j]) {
        greater = false;
        break;
      }
    }
    if (less || greater) amazing++;
  }
  cout << amazing << endl;
  return 0;
}
