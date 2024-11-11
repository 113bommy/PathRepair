#include <bits/stdc++.h>
using namespace std;
long long findgcd(long long a, long long b) {
  if (a == 0 || b == 0 || a == b) return a == b ? a : (a > 0 ? a : b);
  return a > b ? findgcd(b, a % b) : findgcd(a, b % a);
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int num, den;
  if (float(a) / float(b) < float(c) / float(d)) {
    num = (b * c - a * d);
    den = (b * c);
  } else if (float(a) / float(b) > float(c) / float(d)) {
    num = (a * d - b * c);
    den = (a * d);
  } else {
    cout << 0 << endl;
    return 0;
  }
  int k = findgcd(num, den);
  if (k == 1) {
    cout << num << "/" << den << endl;
  } else {
    cout << num / k << "/" << den / k << endl;
  }
  return 0;
}
