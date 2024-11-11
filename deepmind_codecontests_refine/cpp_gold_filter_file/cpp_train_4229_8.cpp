#include <bits/stdc++.h>
using namespace std;
class Doctor {
  int n;
  long long k, m;
  int minx;
  bool check;
  vector<int> a;
  vector<int> c;

 public:
  void ReadInpput() {
    cin >> n >> k;
    int so;
    for (int i = 0; i < n; i++) {
      cin >> so;
      a.push_back(so);
      c.push_back(so);
    }
    sort(c.begin(), c.end());
    m = n;
  }

 public:
  void DemLuot() {
    minx = 0;
    long long dem;
    check = true;
    for (int i = 0; i < n; i++) {
      dem = c[i] - minx;
      if (dem * m <= k) {
        k -= dem * m;
        m--;
        minx = c[i];
      } else {
        check = false;
        dem = k / m;
        minx += dem;
        k = k % m;
        break;
      }
    }
  }

 public:
  void Xuat() {
    if (check && k > 0) {
      cout << "-1" << endl;
      return;
    }
    if (check && k == 0) {
      return;
    }
    int i = 0;
    check = false;
    while (k > 0) {
      while (a[i] <= minx && i < n) i++;
      k--;
      if (a[i] - minx == 1) check = true;
      i++;
    }
    if (check) {
      for (int j = i; j < n; j++)
        if (a[j] - minx == 1) a[j]++;
      minx++;
    }
    if (i >= n) i = 0;
    for (int j = 0; j < n; j++) {
      if (a[(i + j) % n] > minx) cout << (i + j) % n + 1 << " ";
    }
  }
};
int main() {
  Doctor Doli;
  Doli.ReadInpput();
  Doli.DemLuot();
  Doli.Xuat();
  return 0;
}
