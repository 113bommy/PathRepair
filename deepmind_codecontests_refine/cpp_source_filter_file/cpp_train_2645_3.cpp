#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void calc(long long a, long long b) {
  if (a == 1 || b == 1) return;
  ans++;
  calc(a, a % b);
}
int main() {
  long long a, b;
  cin >> a >> b;
  int ans = 0;
  while (a && b) {
    if (a < b) swap(a, b);
    ans += a / b;
    a %= b;
  }
  cout << ans;
}
