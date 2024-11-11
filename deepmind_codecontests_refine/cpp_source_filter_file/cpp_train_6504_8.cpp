#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-12;
double __t;
void quit();
int n, a[4000], res, m;
int notp(int i) {
  if (i > 0)
    return 2 * (notp(i - 1));
  else
    return 1;
}
void v(int i) {
  if (i < m) {
    v(i * 2);
    v(i * 2 + 1);
    int a1 = a[i * 2];
    int a2 = a[i * 2 + 1];
    res += abs(a1 - a2);
    a[i] += max(a1, a2);
  }
}
int main() {
  cin >> n;
  m = notp(n + 1);
  for (int i = 2; i < m; i++) cin >> a[i];
  v(1);
  cout << res;
  quit();
}
void quit() { exit(0); }
