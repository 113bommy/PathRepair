#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  cin >> k;
  if (k > (long long)36) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < ((int)k) / 2; i++) cout << 8;
  if (k % 2) cout << 0;
  return 0;
}
