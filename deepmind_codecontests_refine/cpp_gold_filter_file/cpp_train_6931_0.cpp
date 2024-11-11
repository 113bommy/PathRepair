#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-8;
bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
int main() {
  int n;
  scanf("%d", &(n));
  if (n <= 2)
    puts("1");
  else
    cout << 2 << endl;
  for (int i = 2; i <= n + 1; i++) {
    if (is_prime(i))
      cout << 1 << " ";
    else
      cout << 2 << " ";
  }
}
