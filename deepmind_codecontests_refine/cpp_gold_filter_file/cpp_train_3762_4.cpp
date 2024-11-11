#include <bits/stdc++.h>
using namespace std;
int a[300000];
int main() {
  int n;
  long long s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int j = 0; j < n / 2; j++) {
    s = s + pow((a[j] + a[n - 1 - j]), 2);
  }
  cout << s;
  return 0;
}
