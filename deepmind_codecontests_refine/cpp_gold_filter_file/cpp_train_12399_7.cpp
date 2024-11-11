#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0), b(n + 1, 0);
  long long suma = 0, sumb = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    suma += a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sumb += b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = n, j = n;
  long long ansa = 0, ansb = 0;
  while (i != 0 || j != 0) {
    if (a[i] > b[j]) {
      ansa += a[i];
      if (i > 0) i--;
    } else if (j > 0)
      j--;
    if (b[j] > a[i]) {
      ansb += b[j];
      if (j > 0) j--;
    } else if (i > 0)
      i--;
  }
  cout << ansa - ansb;
}
