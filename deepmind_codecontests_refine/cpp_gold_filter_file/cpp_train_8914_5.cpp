#include <bits/stdc++.h>
using namespace std;
signed long long int d[100000 + 5], mm[100000 + 5];
int bin(int i, int j, signed long long int x) {
  if (i == j) return i;
  if (i + 1 == j) {
    if (mm[j] <= x) return j;
    return i;
  }
  int mid = (i + j) / 2;
  if (mm[mid] <= x)
    return bin(mid, j, x);
  else
    return bin(i, mid, x);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> d[i];
  mm[n] = d[n];
  for (int i = n - 1; i >= 1; --i) mm[i] = min(d[i], mm[i + 1]);
  for (int i = 1; i < n; ++i) {
    if (d[i] <= mm[i + 1])
      cout << "-1 ";
    else
      cout << bin(i + 1, n, d[i] - 1) - i - 1 << ' ';
  }
  cout << -1 << endl;
}
