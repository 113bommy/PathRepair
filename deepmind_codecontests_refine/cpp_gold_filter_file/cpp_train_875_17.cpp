#include <bits/stdc++.h>
using namespace std;
int main() {
  int n[5] = {1, 1, 2, 7, 4};
  int x;
  int m = 10000000;
  for (int i = 0; i < 5; ++i) {
    cin >> x;
    m = min(m, x / n[i]);
  }
  cout << m;
}
