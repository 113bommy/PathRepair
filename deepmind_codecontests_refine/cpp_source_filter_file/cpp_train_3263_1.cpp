#include <bits/stdc++.h>
using namespace std;
long long n, kunci, x, i;
int main() {
  cin >> x;
  for (i = 0; i < x; i++) {
    cin >> n;
    if (n - 1 % 2 == 0)
      kunci = 2;
    else
      kunci = 1;
    if (n % 2 == 0)
      cout << n * 4 + 1 << " ";
    else
      cout << n * kunci + 1 << " ";
  }
}
