#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n <= m) {
    if (n <= k) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  } else {
    cout << "No";
  }
  return 0;
}
