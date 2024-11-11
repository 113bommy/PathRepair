#include <bits/stdc++.h>
using namespace std;
int x[200005], n, c, j;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  for (int i = 0; i < n; i++) {
    while (j < n && x[j] - x[i] <= 5) {
      j++;
      c = max(c, j - i);
    }
  }
  cout << c << endl;
  return 0;
}
