#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9 + 7;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  ;
  cin >> t;
  ;
  while (t--) {
    long long a, b;
    ;
    cin >> a;
    ;
    ;
    cin >> b;
    ;
    if (a > b) {
      swap(a, b);
    }
    if ((a + b) % 3 == 0 && b - a <= a) {
      cout << "YES" << endl;
      ;
    } else {
      cout << "NO" << endl;
      ;
    }
  }
}
