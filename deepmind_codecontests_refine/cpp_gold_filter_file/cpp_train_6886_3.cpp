#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s = 0, i, n, k;
  cin >> n >> k;
  while (k != n && k % n == 0) {
    k = k / n;
    s++;
  }
  if (k == n) {
    cout << "YES\n" << s;
  } else
    cout << "NO";
}
