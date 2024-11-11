#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  int a[n];
  int b = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
