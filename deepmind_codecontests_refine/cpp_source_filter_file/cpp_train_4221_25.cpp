#include <bits/stdc++.h>
using namespace std;
long long A, ans;
int main() {
  cin >> A;
  while (A != 0) {
    if (A % 8 == 1) ans++;
    A /= 8;
  }
  cout << A;
  return 0;
}
