#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  int l = 0, r = 0;
  cin >> k;
  int c[300005];
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  for (int i = k - 1; i > 0; i--) {
    if (c[i] == c[0])
      continue;
    else {
      l = i - 1;
      break;
    }
  }
  for (int i = 0; i < k; i++) {
    if (c[i] == c[k - 1])
      continue;
    else {
      r = k - i - 1;
      break;
    }
  }
  cout << max(l, r);
}
