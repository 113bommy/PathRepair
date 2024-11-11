#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, counter = 0;
  cin >> n;
  string a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (j = 0; j < 7; j++) {
    int c = 0;
    for (i = 0; i < n; i++) {
      if (((int)a[i][j] - 48) | 0) c++;
    }
    counter = max(counter, c);
  }
  cout << counter;
  return 0;
}
