#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n - 1];
  for (long long int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  sort(a, a + (n - 1));
  for (long long int i = 0; i < n; i++) {
    if (a[i] == i + 1) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}
