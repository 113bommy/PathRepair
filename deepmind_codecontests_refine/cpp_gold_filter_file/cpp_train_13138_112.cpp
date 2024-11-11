#include <bits/stdc++.h>
using namespace std;
int z[2000001], m;
int main() {
  string a;
  cin >> a;
  int l = 0, r = 0, ma = 0;
  z[0] = a.size();
  for (int i = 1; i < a.size(); i++) {
    if (i > r) {
      l = i;
      r = i;
      while (a[r] == a[r - l]) r++;
      z[i] = r - l;
      --r;
    } else if (z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      l = i;
      while (a[r] == a[r - l]) r++;
      z[i] = r - l;
      --r;
    }
    if (z[i] + i == a.size()) {
      if (z[i] > ma && z[i] <= m) {
        ma = z[i];
      }
    }
    m = max(m, z[i]);
  }
  if (ma) {
    for (int i = 0; i < ma; i++) {
      cout << a[i];
    }
  } else {
    printf("Just a legend");
  }
}
