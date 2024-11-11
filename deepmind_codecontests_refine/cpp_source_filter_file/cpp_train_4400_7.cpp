#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p[100];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[j] == i) {
        cout << j;
      }
    }
  }
  return 0;
}
