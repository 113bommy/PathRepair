#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100005] = {}, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cout << a[n - k];
  return 0;
}
