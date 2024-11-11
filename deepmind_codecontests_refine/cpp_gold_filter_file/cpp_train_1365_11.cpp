#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 25;
int a[maxn];
int b[maxn];
int main() {
  int n, D;
  cin >> n >> D;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  a[D - 1] += b[0];
  int j = 0;
  for (int i = 0; i < D - 1; i++) {
    if (a[i] + b[n - j - 1] <= a[D - 1]) {
      j++;
    }
  }
  cout << D - j << endl;
}
