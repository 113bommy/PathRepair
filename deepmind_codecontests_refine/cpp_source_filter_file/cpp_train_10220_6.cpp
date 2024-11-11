#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int q, n, k, a[110];
  cin >> q;
  for (int t = 0; t < q; t++) {
    long long int resp, menor;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    resp = a[0] + k;
    menor = a[0] - k;
    menor < 0 ? menor = 0 : menor = menor;
    for (int i = 1; i < n; i++) {
      if (resp < a[i] - k || a[i] + k < menor) {
        resp = -1;
        break;
      } else if (resp > a[i] + k && a[i] + k >= menor) {
        resp = a[i] + k;
      }
      if (a[i] - k < menor) {
        menor = a[i] - k;
        menor < 0 ? menor = 0 : menor = menor;
      }
    }
    cout << resp << "\n";
  }
  return 0;
}
