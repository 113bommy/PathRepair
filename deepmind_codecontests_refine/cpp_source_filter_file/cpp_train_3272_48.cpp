#include <bits/stdc++.h>
using namespace std;
int main() {
  const int siz = 100;
  int n;
  cin >> n;
  int a[siz];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  return 0;
}
