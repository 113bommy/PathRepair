#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x[100], c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  for (int i = 0; i < n; i++) {
    int k = 0;
    for (int j = 0; j < n; j++) {
      if (x[j] > k) {
        k = x[j];
        x[j] = -1;
        i++;
      }
    }
    c++;
  }
  cout << c;
  return 0;
}
