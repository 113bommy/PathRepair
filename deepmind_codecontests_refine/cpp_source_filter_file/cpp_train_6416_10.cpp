#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  if (n <= 10) {
    if (n < 5) {
      cout << "5\n";
    } else {
      cout << "10\n";
    }
  } else {
    if ((n % 10) < 5) {
      n -= (n % 10);
    } else {
      n += 10 - (n % 10);
    }
    cout << n << "\n";
  }
  return 0;
}
