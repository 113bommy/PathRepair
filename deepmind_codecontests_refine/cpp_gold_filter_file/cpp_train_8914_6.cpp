#include <bits/stdc++.h>
using namespace std;
int n;
int mins[100005], A[100005], sil[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  mins[n] = 1e9 + 10;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = n - 1; i >= 0; i--) {
    mins[i] = min(mins[i + 1], A[i]);
    int kiri = i + 1;
    int kanan = n - 1;
    int res = -1;
    while (kiri <= kanan) {
      int tengah = (kiri + kanan) >> 1;
      if (mins[tengah] >= A[i]) {
        kanan = tengah - 1;
      } else {
        res = tengah;
        kiri = tengah + 1;
      }
    }
    sil[i] = max(res - i - 1, -1);
  }
  for (int i = 0; i < n; i++) cout << sil[i] << ((i == n - 1) ? '\n' : ' ');
}
