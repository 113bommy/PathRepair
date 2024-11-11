#include <bits/stdc++.h>
using namespace std;
int tm[233];
int main() {
  int n, s, h, m;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> h >> m;
    tm[i] = h * 60 + m + 1;
  }
  if (tm[0] > s + 1)
    cout << "0 0";
  else {
    for (int i = 1; i < n; ++i) {
      if (tm[i] - tm[i - 1] > s * 2 + 1) {
        int tmp = tm[i - 1] + s;
        cout << tmp / 60 << ' ' << tmp % 60;
        return 0;
      }
    }
    int tmp2 = tm[n - 1] + s;
    cout << tmp2 / 60 << ' ' << tmp2 % 60;
  }
  return 0;
}
