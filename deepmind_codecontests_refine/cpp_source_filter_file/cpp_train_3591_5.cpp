#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long max = -1, pos = -1;
  if (m != 1) {
    if (max < m - 1) {
      max = m - 1;
      pos = m - 1;
    }
  }
  if (m != n) {
    if (max < n - m) {
      max = n - m;
      pos = m + 1;
    }
  }
  cout << pos;
  return 0;
}
