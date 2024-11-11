#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
int main() {
  int n, m, min, max, a[1010];
  while (cin >> n >> m >> min >> max) {
    int cnt = 0, mf = 0, tf = 0;
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      if (a[i] < min) cnt = INF;
      if (a[i] > max) cnt = INF;
      if (a[i] == min) mf = 1;
      if (a[i] == max) tf = 1;
    }
    if (!mf) cnt++;
    if (!tf) cnt++;
    if (n - m < cnt)
      cout << "Incorrect" << endl;
    else
      cout << "Correct" << endl;
  }
  return 0;
}
