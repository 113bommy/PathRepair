#include <bits/stdc++.h>
using namespace std;
int gcb(int a, int b) { return a ? gcb(b % a, a) : b; }
void solve() {
  int n;
  unsigned long long int a[100001];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int t = 0, temp = 0;
  n--;
  int step = 0;
  while ((1 << ++step) < n) {
    t = 1 << step;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      cout << res;
      continue;
    }
    if (i + t > n) t = (t >> 1);
    a[i + t] += a[i];
    res += a[i];
    cout << res << endl;
  }
}
int main() {
  solve();
  return 0;
}
