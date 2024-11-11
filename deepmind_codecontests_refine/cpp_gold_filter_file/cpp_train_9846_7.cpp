#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, total = 0, top;
  cin >> n;
  int num[n];
  for (i = 0; i < n; i++) {
    cin >> num[i];
    total += num[i];
  }
  top = num[0];
  for (i = 1; i < n; i++) {
    if (top < num[i]) {
      top = num[i];
    }
  }
  if (total == top * n) {
    cout << 0;
  } else {
    cout << top * n - total;
  }
  return 0;
}
