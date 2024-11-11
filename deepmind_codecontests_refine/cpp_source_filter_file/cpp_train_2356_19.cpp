#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a[10005];
  long long int c = 0, d = 0;
  cin >> n;
  long long int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i < n - 1; i++) {
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) c++;
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) d++;
  }
  cout << c + d << endl;
  return 0;
}
