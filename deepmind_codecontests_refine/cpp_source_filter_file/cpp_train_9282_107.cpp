#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m >= n && k >= m) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
