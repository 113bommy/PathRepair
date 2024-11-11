#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, l, c = 0;
  cin >> n;
  vector<long long> a;
  long long cnt(long long);
  for (i = 1; i < 101; i++) {
    l = cnt(i);
    if (l + i == n) {
      c++;
      a.push_back(i);
    }
  }
  if (n > 200) {
    for (i = n - 100; i < n; i++) {
      l = cnt(i);
      if (l + i == n) {
        c++;
        a.push_back(i);
      }
    }
  }
  cout << c << endl;
  if (c == 0) {
    return 0;
  }
  for (auto x : a) {
    cout << x << endl;
  }
  return 0;
}
long long cnt(long long n) {
  long long x = 0;
  while (n) {
    x += n % 10;
    n /= 10;
  }
  return x;
}
