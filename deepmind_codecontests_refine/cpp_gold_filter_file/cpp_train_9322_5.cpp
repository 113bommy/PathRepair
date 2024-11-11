#include <bits/stdc++.h>
using namespace std;
int binarySearch(array<int, 2> ar[], int x, int s, int f) {
  int k = (s + f) / 2;
  if (f - s > 1) {
    if (ar[k][0] == x) return k;
    if (ar[k][0] < x) return binarySearch(ar, x, k, f);
    if (ar[k][0] > x) return binarySearch(ar, x, s, k);
  }
  if (x >= ar[f][0]) return f;
  return s;
}
int main() {
  int n;
  cin >> n;
  int x[int(pow(10, 5))];
  int a;
  for (int i = 0; i < int(pow(10, 5)); i++) {
    x[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    x[a - 1]++;
  }
  for (int i = 1; i < int(pow(10, 5)); i++) {
    x[i] += x[i - 1];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a;
    if (a < int(pow(10, 5)))
      cout << x[a - 1] << endl;
    else
      cout << x[int(pow(10, 5)) - 1] << endl;
  }
  return 0;
}
