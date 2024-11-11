#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j, xm, ym, xa[200001], ya[200001];
  cin >> n >> j >> xm >> ym;
  for (int i = 0; i < n; i++) {
    cin >> xa[i] >> ya[i];
  }
  for (int i = 1; i <= j % (2 * n); i++) {
    xm = xa[(i - 1) % n] * 2 - xm;
    ym = ya[(i - 1) % n] * 2 - ym;
  }
  cout << xm << " " << ym;
}
