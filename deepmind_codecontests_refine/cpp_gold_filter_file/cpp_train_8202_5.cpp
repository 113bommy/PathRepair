#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, ans = 0;
  cin >> N;
  for (int p = 1; N / p - 1 > p; p++) {
    if (N % p == 0) ans += N / p - 1;
  }
  cout << ans << endl;
}