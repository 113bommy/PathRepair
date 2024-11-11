#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l[100], r[100];
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    if (r[i] >= k) {
      cout << n - i;
      break;
    }
  }
  return 0;
}
