#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if ((m - n) >= 1 && (k - n) >= 1) {
    cout << "yes";
  } else {
    cout << "no";
  }
  return 0;
}
