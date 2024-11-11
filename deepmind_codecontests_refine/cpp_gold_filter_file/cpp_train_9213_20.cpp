#include <bits/stdc++.h>
using namespace std;
long long k;
int get_sg(long long n) {
  if (!(k & 1)) {
    if (n < 3) return n;
    if (n & 1) return 0;
    return 1;
  }
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 0;
  if (n == 3) return 1;
  if (n == 4) return 2;
  if (n & 1) return 0;
  if (get_sg(n / 2) == 1) return 2;
  return 1;
}
int main() {
  long long n;
  cin >> n >> k;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ans ^= get_sg(x);
  }
  if (ans)
    cout << "Kevin\n";
  else
    cout << "Nicky\n";
  return 0;
}
