#include <bits/stdc++.h>
using namespace std;
const int MX = 1234567;
const double PI = acos(-1.0), EPS = 1e-9;
long long N, arr[MX];
long long gcd(long long a, long long b) {
  while (a > 0 && b > 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int main() {
  cin >> N;
  long long g = 0;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < N; i++) {
    g = gcd(g, arr[i]);
  }
  if (g != 1) {
    cout << "YES\n";
    cout << 0 << "\n";
    return 0;
  }
  int oper = 0;
  for (int i = 0; i < N - 1; i++) {
    if (arr[i] % 2 && arr[i + 1] % 2) {
      i++;
      oper++;
    } else if (arr[i] % 2 && arr[i + 1] % 2 == 0) {
      i++;
      oper += 2;
    }
  }
  cout << "YES\n";
  cout << oper << "\n";
  return 0;
}
