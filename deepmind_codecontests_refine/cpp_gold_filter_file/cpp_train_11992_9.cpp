#include <bits/stdc++.h>
using namespace std;
int main() {
  int f;
  cin >> f;
  string n;
  int z = 0, k = 0;
  cin >> n;
  for (int i = 0; i < n.length(); i++) {
    if (n[i] == 'z') {
      z++;
    }
    if (n[i] == 'n') {
      k++;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << 1 << ' ';
  }
  for (int i = 0; i < z; i++) {
    if (i == z - 1) {
      cout << 0;
    } else {
      cout << 0 << ' ';
    }
  }
}
