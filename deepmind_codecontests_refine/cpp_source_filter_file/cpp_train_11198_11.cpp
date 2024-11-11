#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, len = -1;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    len = len == -1 ? r - l + 1 : min(len, r - l + 1);
  }
  cout << len << "\n";
  for (long long i = 0; i < n; i++) cout << i % len << " ";
  return 0;
}
