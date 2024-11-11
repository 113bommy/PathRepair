#include <bits/stdc++.h>
using namespace std;
int a[6];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cout << (a[0] + a[n - 1]) / 2;
}
