#include <bits/stdc++.h>
using namespace std;
long long p[100005];
stack<long long> m;
void solve() {
  long long a, b, c = 0, d = 0;
  cin >> a;
  for (long long i = 1; i <= a; i++) {
    cin >> p[i];
    c = max(c, p[i]);
    d += p[i];
  }
  if (d - c < c || d % 2 == 1)
    cout << "T" << endl;
  else
    cout << "HL" << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
