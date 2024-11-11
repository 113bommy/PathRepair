#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  string p;
  cin >> p;
  for (int i = 0; i < t; i++) {
    int j = 0;
    while (j < n - 1) {
      if (p[j] == 'B' && p[j + 1] == 'G') {
        swap(p[j], p[j + 1]);
        j += 2;
      }
      j++;
    }
  }
  cout << p;
}
