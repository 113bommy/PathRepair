#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, s, p;
  cin >> k >> n >> s >> p;
  int trungbinh = (n - 1) / s + 1;
  int tongcong = s * k;
  int tongsogiay = (tongcong - 1) / p + 1;
  cout << tongsogiay;
}
