#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, m;
  long long ans;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  if (n == 1) {
    if (m % 6 <= 3) {
      ans = m - m % 6;
    } else {
      ans = m - (6 - (m % 6));
    }
  } else if (n == 2 && m == 2) {
    ans = 0;
  } else if (n == 2 && m == 3) {
    ans = 4;
  } else if (n == 2 && m == 7) {
    ans = 12;
  } else {
    if (n % 2 == 1 && m % 2 == 1) {
      ans = n * m - 1;
    } else {
      ans = n * m;
    }
  }
  cout << ans << endl;
}
