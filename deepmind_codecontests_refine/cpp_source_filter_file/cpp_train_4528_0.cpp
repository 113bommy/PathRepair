#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[3003];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long co = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      co += a[i - 1] - a[i] + 1;
      a[i] = a[i - 1] + 1;
    }
  }
  cout << co << endl;
  return 0;
}
