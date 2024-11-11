#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, k;
  long long n;
  cin >> t;
  while (t--) {
    long long c = 0;
    cin >> n;
    c = (n + 1) * n / 2;
    for (int i = 1; i <= n; i *= 2) {
      c -= i * 2;
    }
    cout << c;
  }
}
