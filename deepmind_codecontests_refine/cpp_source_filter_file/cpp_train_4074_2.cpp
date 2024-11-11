#include <bits/stdc++.h>
int ngaydu(int a[], int x) {
  int kq = 15;
  int dem = 0;
  for (int i = 1; i < 15; i++) {
    if (a[i])
      for (int j = i; j < 15; j++) {
        if (a[i]) {
          dem++;
        }
        if (dem == x) {
          kq = std::min(kq, j - i + 1);
          break;
        }
      }
    dem = 0;
  }
  return kq;
}
int dayneed(long long x, int a[]) {
  int dem = 0;
  int last = 0;
  for (int i = 1; i <= 7; i++) {
    if (a[i]) {
      dem++;
    }
  }
  long long kq;
  if (x % dem == 0)
    kq = 7 * (x / dem - 1) + ngaydu(a, dem);
  else
    kq = 7 * (x / dem) + ngaydu(a, x % dem);
  return kq;
}
int main() {
  int t;
  std::cin >> t;
  long long k;
  int a[15];
  while (t--) {
    std::cin >> k;
    for (int i = 1; i <= 7; i++) {
      std::cin >> a[i];
      a[i + 7] = a[i];
    }
    std::cout << dayneed(k, a) << std::endl;
  }
  return 0;
}
