#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[100009], b[100009], sum = 0, cnta = 0, cntb = 0, cnt1a = 0,
                                  cnt1b = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      cnta++;
    } else {
      cnt1a++;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (a[i] % 2 == 0) {
      cntb++;
    } else {
      cnt1b++;
    }
  }
  if (cnta >= cnt1b) {
    sum += cnt1b;
  } else {
    sum += cnta;
  }
  if (cnt1a >= cntb) {
    sum += cntb;
  } else {
    sum += cnt1a;
  }
  cout << sum << endl;
}
