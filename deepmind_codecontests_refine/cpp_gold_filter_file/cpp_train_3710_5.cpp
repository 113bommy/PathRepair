#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int main() {
  int a1, h1, c1, a2, h2;
  cin >> h1 >> a1 >> c1 >> h2 >> a2;
  int n;
  for (int i = 1; i < 100000; i++) {
    if (h2 <= 0) {
      n = i - 1;
      break;
    }
    if (h1 > a2 || a1 >= h2) {
      arr[i] = 1;
      h2 -= a1;
      h1 -= a2;
    } else {
      arr[i] = 0;
      h1 += c1;
      h1 -= a2;
    }
  }
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      cout << "STRIKE" << endl;
    } else {
      cout << "HEAL" << endl;
    }
  }
}
