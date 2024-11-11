#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  n--;
  if (n <= 4) {
    cout << "NO";
    return 0;
  }
  if (n % 2 == 0) {
    if ((n - 2) % 2 == 0)
      cout << 1 << " " << (n - 2) / 2;
    else
      cout << "NO\n";
  } else {
    cout << "NO";
  }
}
