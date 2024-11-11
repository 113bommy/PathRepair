#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 1 && n > 1) {
    cout << "-1";
    return 0;
  }
  if (n == 1 && k == 1) {
    cout << "a";
    return 0;
  }
  if (k > n) {
    cout << "-1";
    return 0;
  }
  for (int i = 0; i < n - k + 2; i++) {
    if (i % 2 == 0)
      cout << "a";
    else
      cout << "b";
  }
  for (int i = 0; i < k - 2; i++) cout << (char)(99 + i);
}
