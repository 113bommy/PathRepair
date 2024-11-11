#include <bits/stdc++.h>
using namespace std;
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  FAST();
  long long t;
  cin >> t;
  for (int p = 0; p < t; p++) {
    long long n, m;
    cin >> n >> m;
    bool diaga = false, diagb = false;
    for (long long i = 0; i < n; i++) {
      long long a, b, c, d;
      cin >> a >> b;
      cin >> c >> d;
      if (a == d) {
        diaga = true;
      }
      if (b == c) {
        diagb = true;
      }
    }
    if (diaga && diagb) {
      if (m % 2 == 1) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
      }
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
