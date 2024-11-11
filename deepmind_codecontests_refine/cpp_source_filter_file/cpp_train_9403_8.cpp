#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, c = 0;
  cin >> n >> k;
  int *a = new int[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    if (a[i] >= a[k] && a[1] != 0) c++;
  }
  cout << c << endl;
}
