#include <bits/stdc++.h>
using namespace std;
long long n, k, aux, halp, a, b, mid;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  a = 1;
  b = 1000000000;
  while (b > a) {
    mid = (a + b) / 2;
    aux = k, halp = mid;
    while (mid / aux > 0) halp += mid / aux, aux *= k;
    if (halp >= n) {
      b = mid - 1;
    } else
      a = mid + 1;
  }
  aux = k, halp = b;
  while (b / aux > 0) halp += b / aux, aux *= k;
  if (halp >= n) {
    cout << b;
  } else
    cout << b + 1;
}
