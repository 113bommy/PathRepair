#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long p) {
  if (p == 0) return 1ll;
  long long ans = power(x, p / 2);
  ans *= ans;
  if (p & 1) return ans * x;
  return ans;
}
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  long long id = 0;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    while (id > x) x += y;
    id = x;
  }
  cout << id << endl;
  return 0;
}
