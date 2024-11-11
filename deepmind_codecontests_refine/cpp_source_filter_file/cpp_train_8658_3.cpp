#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
long long card[maxn];
long long t;
long long z;
long long l, r;
long long n;
long long pow(long long n1, long long n2) {
  long long ans = 1;
  for (int i = 1; i <= n2; i++) {
    ans *= n1;
  }
  return ans;
}
int main() {
  cin >> n;
  cin >> l >> r;
  int p1 = pow(2, l - 1);
  int p2 = pow(2, r - 1);
  cout << (n - l + 1) + 2 * (1 - pow(2, l - 1)) / (1 - 2) << " ";
  cout << (n - r + 1) * pow(2, r - 1) + (1 - pow(2, r - 1)) / (-1);
}
