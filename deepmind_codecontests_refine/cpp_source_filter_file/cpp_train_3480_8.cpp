#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int A = b / (k - 1);
  int B = b % (k - 1) + 1;
  int ans = 0;
  if (A * k * v >= a) return cout << (a + k * v - 1) / k * v << endl, 0;
  a -= A * k * v;
  ans += A;
  if (B * v >= a) return cout << ans + 1 << endl, 0;
  ans++;
  a -= B * v;
  ans += (a + v - 1) / v;
  cout << ans << endl;
}
