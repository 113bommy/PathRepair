#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int daging[n], hargaDaging[n], ans = 0, minimalHarga = 101, temp = 0;
  for (int i = 0; i < n; i++) {
    cin >> daging[i] >> hargaDaging[i];
  }
  for (int i = 0; i < n; i++) {
    if (hargaDaging[i] < minimalHarga) {
      ans += temp * minimalHarga;
      minimalHarga = hargaDaging[i];
      temp = daging[i];
    } else
      temp += daging[i];
    if (i == n - 1) {
      ans += temp * minimalHarga;
    }
  }
  cout << ans << "\n";
}
