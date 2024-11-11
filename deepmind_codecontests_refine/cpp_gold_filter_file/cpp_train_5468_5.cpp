#include <bits/stdc++.h>
using namespace std;
int fx4[] = {+1, -1, +0, +0};
int fy4[] = {+0, +0, +1, -1};
int fx8[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy8[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int main() {
  int n, m;
  cin >> n >> m;
  int a[200000 + 7], r[200000 + 7], t[200000 + 7];
  for (int i = int(0); i <= int(n - 1); i++) {
    cin >> a[i];
  }
  int R, T, s = 0, b[200000 + 7], bl, br;
  for (int i = int(0); i <= int(m - 1); i++) {
    cin >> T >> R;
    while (s > 0 && R >= r[s - 1]) {
      s--;
    }
    t[s] = T, r[s] = R, ++s;
  }
  bl = 0, br = r[0], r[s] = 0, s++;
  for (int i = int(0); i <= int(r[0] - 1); i++) {
    b[i] = a[i];
  }
  sort(b, b + br);
  for (int i = int(1); i <= int(s - 1); i++) {
    for (int j = r[i - 1]; j > r[i]; --j) {
      if (t[i - 1] == 1) {
        br--;
        a[j - 1] = b[br];
      } else {
        a[j - 1] = b[bl];
        bl++;
      }
    }
  }
  for (int i = int(0); i <= int(n - 1); i++) {
    cout << a[i] << " ";
  }
  return 0;
}
