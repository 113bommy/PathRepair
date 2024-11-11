#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, a[1000];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] <= a[j]) swap(a[i], a[j]);
    }
  }
  long tong = 0;
  for (int i = 0; i < n - 1; i++) {
    tong += (a[i] - 1 - a[i - 1]);
  }
  cout << tong;
}
