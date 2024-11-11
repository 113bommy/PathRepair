#include <bits/stdc++.h>
using namespace std;
const int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
  int i, j, k, a, b, c, d;
  int n, ar[110], mx;
  cin >> n;
  for (i = 0; i < n; i++) cin >> ar[i];
  mx = ar[0];
  for (i = 0; i < n; i++) {
    int tem = ar[i];
    for (j = i; j < n; j++) {
      if (tem > mx) mx = tem;
      tem ^= ar[j];
    }
    if (tem > mx) mx = tem;
  }
  cout << mx << endl;
  return 0;
}
