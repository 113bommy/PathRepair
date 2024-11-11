#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int first, second, a, b;
  cin >> first >> second >> a >> b;
  long long lcm = 0;
  for (long long i = max(first, second); i <= (long long)first * second; i++)
    if (i % first == 0 && i % second == 0) {
      lcm = i;
      break;
    }
  int cnt = 0;
  if (lcm > b)
    cout << cnt;
  else {
    if (a % lcm != 0) a += lcm - (a % lcm);
    if (b % lcm != 0) b -= b % lcm;
    cnt = (b - a) / lcm + 1;
    cout << cnt;
  }
  return 0;
}
