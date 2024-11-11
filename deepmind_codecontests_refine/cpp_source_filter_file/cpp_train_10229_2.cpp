#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, n;
    cin >> a >> b >> n;
    long long int p1, p2;
    p1 = a;
    p2 = b;
    long long int k = 0;
    a = min(p1, p2);
    b = max(p1, p2);
    long long int cnt = 0;
    while (a < n && b < n) {
      if (cnt == 0) {
        a += b;
        cnt = 1;
        k++;
      } else {
        b += a;
        cnt = 0;
        k++;
      }
    }
    cout << k << endl;
  }
}
