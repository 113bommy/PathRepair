#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k = 0;
  cin >> n >> m;
  long long int a[n + 5], b[m + 5], c[n + m + 5];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i] == a[j]) {
        c[k] = j;
        k++;
      }
    }
  }
  sort(c, c + k);
  for (int i = 0; i < k; i++) {
    cout << a[c[i]] << " ";
  }
}
