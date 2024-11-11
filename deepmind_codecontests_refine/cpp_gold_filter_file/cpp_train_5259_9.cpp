#include <bits/stdc++.h>
using namespace std;
int delta_x[] = {-1, 0, 1, 0};
int delta_y[] = {0, 1, 0, -1};
inline long long gcd(long long a, long long b) {
  return (a ? gcd(b % a, a) : b);
}
int n, f[111111];
int main() {
  scanf("%d", &n);
  int r = 0;
  for (int i = (1); i <= (n); i++) {
    int x;
    scanf("%d", &x);
    f[x] = f[x - 1] + 1;
    r = max(r, f[x]);
  }
  cout << n - r;
}
