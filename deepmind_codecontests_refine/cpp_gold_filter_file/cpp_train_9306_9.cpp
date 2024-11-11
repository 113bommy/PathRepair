#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, n, d;
  int kol = 0;
  cin >> n >> d;
  int *a = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j && abs(a[i] - a[j]) <= d) {
        kol++;
      }
  cout << kol;
  return 0;
}
