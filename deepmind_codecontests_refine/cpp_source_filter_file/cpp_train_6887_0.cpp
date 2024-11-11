#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;
int main() {
  cin >> n >> k;
  while (k > n) {
    k /= n;
    cnt++;
  }
  if (k != n) cout << "NO";
  if (k == n) cout << "YES" << endl << cnt;
  return 0;
}
