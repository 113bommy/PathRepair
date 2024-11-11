#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    unsigned long long int a[n], sum = 0, temp = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sum = (unsigned long long int)accumulate(a, a + n, sum);
    for (int i = 0; i < n; i++) {
      temp += a[i];
      if (temp >= (sum + 1) / 2) {
        cout << i + 1 << '\n';
        break;
      }
    }
  }
  return 0;
}
