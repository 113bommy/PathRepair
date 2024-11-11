#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main() {
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i += 2) {
    b[i] = a[n / 2 + i / 2];
  }
  for (int i = 1; i < n; i += 2) {
    b[i] = a[i / 2];
  }
  for (int i = 1; i < n - 1; i++) {
    if (b[i] < b[i - 1] && b[i] < b[i + 1]) sum++;
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
