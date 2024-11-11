#include <bits/stdc++.h>
using namespace std;
map<long long, long long> ms;
bool ok(long long a, long long b) {
  while (a <= b) {
    if (a == b)
      return 1;
    else
      b /= 2;
  }
  return 0;
}
long long findr(long long a, long long b) {
  while (b) {
    if (ok(b, a))
      return b;
    else
      b /= 2;
  }
}
void add(long long root, long long x, long long num) {
  while (x / 2 >= root) {
    ms[x] += num;
    x = x / 2;
  }
}
long long sum(long long root, long long x) {
  long long ans = 0;
  while (x / 2 >= root) {
    ans += ms[x];
    x = x / 2;
  }
  return ans;
}
int main() {
  int q, t;
  long long a, b, c, mid;
  cin >> q;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> c;
      mid = findr(a, b);
      add(mid, a, c);
      add(mid, b, c);
    } else {
      cin >> a >> b;
      mid = findr(a, b);
      cout << sum(mid, a) + sum(mid, b) << endl;
    }
  }
  return 0;
}
