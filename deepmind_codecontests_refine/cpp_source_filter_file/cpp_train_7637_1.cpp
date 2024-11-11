#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long res;
  int a[n + 1];
  int last = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1) {
      res += a[i] + 1;
    } else {
      res++;
      res += abs(a[i - 1] - a[i]) + 1;
    }
  }
  cout << res;
}
