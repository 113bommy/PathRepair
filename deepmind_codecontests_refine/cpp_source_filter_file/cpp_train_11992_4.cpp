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
  for (int i = 0; i < z; i++) {
    cout << 0 << ' ';
  }
  for (int i = 0; i < k; i++) {
    if (i == k - 1) {
      cout << 1;
    } else {
      cout << 1 << ' ';
    }
  }
}
