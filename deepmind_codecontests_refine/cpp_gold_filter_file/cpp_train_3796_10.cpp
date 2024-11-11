#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long ret = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  ret = k * (6 * (n - 1) + 5);
  cout << ret << endl;
  for (int i = 0; i < n; i++) {
    cout << (6 * i + 1) * k << " " << (6 * i + 2) * k << " " << (6 * i + 3) * k
         << " " << (6 * i + 5) * k << endl;
  }
  return 0;
}
