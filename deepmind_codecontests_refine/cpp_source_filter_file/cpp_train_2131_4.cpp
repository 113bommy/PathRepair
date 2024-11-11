#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a - (a / b * b));
}
vector<int> v;
bool bt(int n, int a, int b, int c) {
  if (n < 0) return false;
  if (n == 0) return true;
  if (n >= a) {
    v.push_back(a);
    if (!bt(n - a, a, b, c))
      v.pop_back();
    else
      return true;
  }
  if (n >= b) {
    v.push_back(b);
    if (!bt(n - b, a, b, c))
      v.pop_back();
    else
      return true;
  }
  if (n >= c) {
    v.push_back(c);
    if (!bt(n - c, a, b, c))
      v.pop_back();
    else
      return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  int temp = n;
  int cnt = 0;
  for (int i = 0; i < 11; i++) {
    cnt++;
    temp = n + cnt;
    while (abs(temp) > 0) {
      if (abs(temp) % 10 == 8) {
        cout << cnt << endl;
        return 0;
      }
      temp /= 10;
    }
  }
  return 0;
}
