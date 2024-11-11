#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x = x * 100;
    p[i] = x;
  }
  int tot_orange = 0;
  for (int i = 0; i < n; i++) {
    tot_orange += p[i];
  }
  double x = tot_orange * 100.00;
  int tot_vol = n * 10000;
  double res = (x / tot_vol);
  cout << res << endl;
}
