#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, s1 = 0, s2 = 0, i;
  cin >> t;
  while (t--) {
    s1 = 0;
    s2 = 0;
    cin >> n;
    s1 = (long long)pow(2, n);
    for (i = 1; i <= n / 2 - 1; i++) s1 = s1 + (long long)pow(2, i);
    for (i = n / 2; i < n; i++) s2 = s2 + (long long)pow(2, i);
    cout << abs(s1 - s2) << '\n';
  }
}
