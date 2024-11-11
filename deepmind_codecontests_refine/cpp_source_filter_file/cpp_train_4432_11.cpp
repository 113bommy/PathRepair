#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
int main() {
  long long n;
  char c;
  cin >> n >> c;
  long long ans = 0;
  if (n <= 4)
    ans = 0;
  else
    ans += n / 4 * 16;
  if (n % 4 == 1 || n % 4 == 3)
    ans += 0;
  else
    ans += 7;
  if (c == 'f') ans++;
  if (c == 'e') ans += 2;
  if (c == 'd') ans += 3;
  if (c == 'c') ans += 4;
  if (c == 'b') ans += 5;
  if (c == 'a') ans += 6;
  cout << ans << endl;
  return 0;
}
