#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
long long a[maxn];
int n;
long long gcd(long long a, long long b) {
  if (b != 0)
    return gcd(b, a % b);
  else
    return a;
}
bool judge(long long t) {
  if (t % 2 == 0) t = t / 2;
  if (t % 3 == 0) t = t / 3;
  return t == 1;
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool f = true;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[0]) continue;
      long long t = gcd(a[0], a[i]);
      long long t1 = a[0] / t;
      long long t2 = a[i] / t;
      if (!judge(t1) || !judge(t2)) {
        f = false;
        break;
      }
    }
    if (f)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
