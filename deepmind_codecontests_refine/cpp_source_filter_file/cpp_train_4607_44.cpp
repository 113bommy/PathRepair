#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long res = binpow(a, b / 2);
  res *= res;
  if (b % 2) {
    return res * a;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string to_upper(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << a + b;
  }
  return 0;
}
