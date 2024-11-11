#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  int a[6];
  for (int i = 0; i < 6; ++i) {
    cin >> a[i];
  }
  int x1 = min(a[2], a[4]), x2 = min(a[2], a[4]), x3 = min(a[1], a[5]);
  int64_t ct = x1 * (2 * a[3] + x1);
  a[3] += x1;
  ct += (x2 - x1) * 2 * a[3];
  ct += x3 * (2 * a[0] + x3);
  cout << ct << endl;
  return 0;
}
