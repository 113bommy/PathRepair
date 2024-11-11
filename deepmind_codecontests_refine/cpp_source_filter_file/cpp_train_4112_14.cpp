#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int dig = 1;
  long long prev = 1;
  long long next = 10;
  long long ans = 0;
  while (next < n) {
    ans += (next - prev) * dig;
    prev = next;
    next = prev * 10;
    dig++;
  }
  ans += (n - prev + 1) * (dig);
  cout << ans << endl;
}
