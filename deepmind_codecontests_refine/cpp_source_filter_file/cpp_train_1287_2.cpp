#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  int x;
  long long s;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s += x;
  }
  if (s % n == 0) return n;
  return n - 1;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    cout << solve() << endl;
  }
}
