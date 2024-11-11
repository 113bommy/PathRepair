#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[100006];
int b[100006];
int d[2 * 100006];
int tn = 0;
int main() {
  cin >> n >> m >> k;
  map<int, int> ma, mb;
  for (int i = 0; i != n; i++) {
    cin >> a[i];
    d[tn++] = a[i];
    ma[a[i]]++;
  }
  for (int i = 0; i != n; i++) {
    cin >> b[i];
    d[tn++] = b[i];
    mb[b[i]]++;
  }
  sort(d, d + tn);
  tn = unique(d, d + tn) - d;
  int tans = 0;
  for (int i = tn - 1; i >= 0; i--) {
    tans += ma[d[i]] - mb[d[i]];
    if (tans > 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
