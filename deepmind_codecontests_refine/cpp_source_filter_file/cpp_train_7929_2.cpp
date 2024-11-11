#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 3;
int a[N], b[N];
int main() {
  int maxa, maxb;
  int n, m, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  maxa = a[0];
  maxb = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > maxa) {
      maxa = a[i];
    }
  }
  for (int i = 1; i < m; i++) {
    if (b[i] > maxb) {
      maxb = b[i];
    }
  }
  cout << maxa << " " << maxb;
}
