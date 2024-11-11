#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, a[100010];
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  long long int c = 0;
  for (i = 2; i < n; i++) {
    if (a[i] > a[1] && a[i] < a[n]) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
