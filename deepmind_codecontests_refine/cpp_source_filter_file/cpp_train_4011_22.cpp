#include <bits/stdc++.h>
using namespace std;
long long int xpow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long int k = xpow(a, b / 2);
    return k * k;
  }
  if (b % 2 != 0) return a * xpow(a, b - 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int s, x;
  cin >> s >> x;
  long long int temp = x;
  long long int an = (s - x) / 2;
  if ((s - x) % 2 != 0 or (s - x) < 0 or (an and x)) {
    cout << "0" << endl;
    return 0;
  }
  int cnt = 0;
  vector<int> bin;
  while (x != 0) {
    int t = x % 2;
    if (t == 1) cnt++;
    x /= 2;
  }
  if (s == temp)
    cout << xpow(2, cnt) - 2 << endl;
  else
    cout << xpow(2, cnt) << endl;
  return 0;
}
