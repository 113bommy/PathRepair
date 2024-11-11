#include <bits/stdc++.h>
using namespace std;
bool is_sort(int ar[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (ar[i] > ar[i + 1]) return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  int n, x, ar[105] = {0}, ty;
  ty = t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      ar[x]++;
    }
  }
  for (int i = 0; i < 100; i++) {
    if (ar[i] == ty) {
      cout << i << ' ';
    }
  }
}
