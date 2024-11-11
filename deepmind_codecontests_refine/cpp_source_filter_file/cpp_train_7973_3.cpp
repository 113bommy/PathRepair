#include <bits/stdc++.h>
using namespace std;
int q;
void init() { cin >> q; }
bool check(long long x, long long n) {
  long long k = n - (x + 1) / 2;
  return k * (k - 1) / 2 + (x + 1) / 2 >= x;
}
long long calc(long long n) {
  long long l = n - 1, r = 2 * n - 2;
  long long i = (l + r) / 2;
  while (l != i && i != r) {
    if (check(i, n))
      l = i;
    else
      r = i;
    i = (l + r) / 2;
  }
  for (int i = r; i >= l; i--)
    if (check(i, n)) return i;
  return -1;
}
void process() {
  while (q--) {
    int n;
    cin >> n;
    cout << calc(n) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
  process();
}
