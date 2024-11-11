#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) return power(a * a % 1000000007, b / 2);
  return a * power(a, b - 1) % 1000000007;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  int n, t;
  cin >> n >> t;
  string a;
  cin >> a;
  int i = 0, j = 0;
  while (a[i] != '.') i++;
  i++;
  j = i;
  while (i < a.size()) {
    if (i - j + 1 > t) j++;
    if (a[i] == '4')
      i++;
    else {
      if (a[i] < '4') {
        i++;
        j = i;
        continue;
      }
      if (a[i] > '4') {
        break;
      }
    }
  }
  if (j == a.size()) {
    cout << a;
    return 0;
  }
  a = a.substr(0, j);
  i = a.size() - 1;
  while (i >= 0) {
    if (a[i] == '.') {
      i--;
      continue;
    }
    a[i]++;
    if (a[i] > '9') {
      a[i]--;
      i--;
    } else
      break;
  }
  if (i < 0) a = "1" + a;
  i = a.size() - 1;
  while (a[i] == '0') i--;
  if (a[i] == '.') i--;
  a.erase(a.begin() + i + 1, a.end());
  cout << a;
  return 0;
}
