#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, a[100009], sum = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    sum = sum + a[i];
  }
  if (sum + (n - 1) == x) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
