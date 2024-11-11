#include <bits/stdc++.h>
using namespace std;
void subString(string s, int n) {
  for (int i = 0; i < n; i++)
    for (int len = 1; len <= n - i; len++)
      cout << s.substr(i, len) << " " << s.substr(n - i - 1, len) << endl;
}
int main() {
  int m;
  cin >> m;
  int a[m];
  for (int j = 0; j < m; j++) {
    cin >> a[j];
  }
  int n;
  cin >> n;
  int b[n];
  for (int j = 0; j < n; j++) {
    cin >> b[j];
  }
  sort(a, a + m);
  sort(b, b + n);
  int sum = 0, l = m - 1, k = 0;
  for (int j = n - 1; j >= 0; j--) {
    k++;
    sum = sum + b[j];
    if (k == a[l]) {
      j = j - 2;
      k = 0;
    }
  }
  cout << sum << endl;
  return 0;
}
