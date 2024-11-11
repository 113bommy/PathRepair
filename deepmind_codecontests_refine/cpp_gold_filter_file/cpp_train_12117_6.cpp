#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  cin >> n;
  int nn = 0;
  long long a[20000][2];
  for (int p = 0; p < 20000; p++) {
    a[p][0] = 0;
    a[p][1] = 0;
  }
  for (int i = 0; i < n; i++) {
    int aa, ss;
    cin >> aa >> ss;
    if (aa >= 0) {
      a[aa + 10000][0] = aa;
      a[aa + 10000][1] = ss;
    } else {
      a[10000 + aa][0] = -aa;
      a[10000 + aa][1] = ss;
    }
  }
  for (int o = 0; o < 20000; o++) {
    if (o + a[o][1] >= 0 && o + a[o][1] < 20000 && a[o][0] > 0) {
      if (a[o + a[o][1]][1] == -a[o][1]) {
        nn = 1;
        break;
      }
    }
  }
  if (nn == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
