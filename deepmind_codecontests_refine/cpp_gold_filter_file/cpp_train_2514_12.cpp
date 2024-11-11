#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  long long int n, a[9], i;
  string x;
  cin >> n >> x;
  for (i = 0; i < 9; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    if (x[i] - 48 < a[x[i] - 49]) {
      while (x[i] - 48 <= a[x[i] - 49]) {
        x[i] = a[x[i] - 49] + 48;
        i++;
        if (i >= n) break;
      }
      break;
    }
  }
  cout << x;
  return (0);
}
