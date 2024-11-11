#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> as(n, 0);
  for (int i = 0; i < n; i++) cin >> as[i];
  if (n == 1) {
    cout << "1 1\n" << -as[0] << "\n";
    cout << "1 1\n0\n1 1\n0\n";
    return 0;
  }
  int len = n - 1;
  cout << "1 " << len << "\n";
  for (int i = 0; i < len; i++) {
    cout << (long long)(as[i] % n) * len;
    if (i < len - 1) cout << " ";
    as[i] += (as[i] % n) * len;
  }
  cout << "\n" << n << " " << n << "\n" << -as[len] + n << "\n";
  as[len] -= as[len] - n;
  cout << "1 " << n << "\n";
  for (int i = 0; i < n; i++) {
    cout << -as[i];
    if (i < n - 1) cout << " ";
  }
  cout << "\n";
  return 0;
}
