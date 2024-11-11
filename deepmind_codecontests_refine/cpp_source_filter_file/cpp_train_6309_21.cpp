#include <bits/stdc++.h>
int main() {
  using namespace std;
  long n, k;
  cin >> n >> k;
  if (n < k) {
    cout << "NO\n";
  } else {
    if ((n / k) % 2 == 0) {
      cout << "NO\n";
    } else
      cout << "YES\n";
  }
  return 0;
}
