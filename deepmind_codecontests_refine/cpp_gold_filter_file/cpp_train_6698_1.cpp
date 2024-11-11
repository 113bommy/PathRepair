#include <bits/stdc++.h>
using namespace std;
int i, j, n, a, m, k, mas1[100005], mas2[100005], mas3[100005];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> mas1[i];
  }
  for (i = 0; i < n; i++) {
    cin >> mas2[i];
  }
  for (i = 0; i < n; i++) {
    a = mas1[i] - 1;
    mas3[a] = mas2[i];
  }
  for (i = 0; i < n; i++) {
    cout << mas3[i] << " ";
  }
}
