#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[200], x = 0;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 2 * n; i += 2) {
    for (int j = 1; j < 2 * n; j++)
      if (a[i] == a[j]) x++;
  }
  cout << x;
}
