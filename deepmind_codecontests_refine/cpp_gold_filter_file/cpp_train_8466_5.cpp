#include <bits/stdc++.h>
using namespace std;
unsigned long long calc(unsigned long long x,
                        const vector<unsigned long long> &a,
                        const vector<unsigned long long> &b) {
  unsigned long long result = 0;
  for (int i = 0; i < a.size(); ++i) {
    result += (x * a[i]) / b[i];
  }
  return result;
}
int main() {
  unsigned long long n, c;
  cin >> n >> c;
  vector<unsigned long long> a(n), b(n);
  bool f = true;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    if (a[i] != 0) f = false;
  }
  if (c < n) {
    cout << 0 << endl;
    return 0;
  }
  if (f) {
    cout << -1 << endl;
    return 0;
  }
  unsigned long long cnt = 0;
  for (int x = 1; x < 1000000; ++x) {
    if (calc(x, a, b) == c - n) {
      ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
