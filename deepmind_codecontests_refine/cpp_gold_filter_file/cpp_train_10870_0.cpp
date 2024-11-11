#include <bits/stdc++.h>
using namespace std;
long long sum(long long x) {
  long long pot = 1;
  int dig = 1;
  long long ans = 0;
  while (pot <= x) pot *= 10, dig++;
  pot /= 10;
  dig--;
  while (pot) {
    ans += (x - pot + 1) * dig;
    x = pot - 1;
    pot /= 10;
    dig--;
  }
  return ans;
}
int main(void) {
  long long w, m, k;
  cin >> w >> m >> k;
  long long c = w / k;
  long long beg = 0, end = 1000000000000000000LL, h;
  long long base = sum(m - 1);
  while (beg <= end) {
    h = (beg + end) / 2;
    if (sum(h) - base > c)
      end = h - 1;
    else
      beg = h + 1;
  }
  if (sum(h) - base > c) h--;
  cout << h - m + 1 << endl;
  return 0;
}
