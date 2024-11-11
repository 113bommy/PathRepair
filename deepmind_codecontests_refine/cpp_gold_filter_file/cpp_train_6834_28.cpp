#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n > 36) {
    cout << -1;
    return 0;
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) cout << 8;
    return 0;
  }
  for (int i = 0; i < n / 2; i++) cout << 8;
  cout << 4;
  return 0;
}
