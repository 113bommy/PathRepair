#include <bits/stdc++.h>
using namespace std;
int a[1000100];
int main() {
  int n;
  cin >> n;
  int max1 = 0;
  int uk = 0;
  for (int i = 1; i <= n; i++) {
    int l;
    cin >> l;
    a[l]++;
    if (a[l] > max1) {
      max1 = a[l];
      uk = l;
    }
  }
  cout << uk;
  return 0;
}
