#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, som = 0, j = 0;
  cin >> n >> k;
  int t[n];
  int indice[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    indice[i] = t[i];
  }
  sort(t, t + n);
  for (int i = 0; som < k && i < n; i++) {
    j++;
    som += t[i];
  }
  if (som > k) j--;
  cout << j << endl;
  for (int l = 0; l < j; l++)
    for (int m = 0; m < n; m++)
      if (t[l] == indice[m]) {
        cout << m + 1 << " ";
        indice[m] = -1;
        break;
      }
  return 0;
}
