#include <bits/stdc++.h>
using namespace std;
long long t, n, k, d1, d2;
long long x2[4], x3[4], x1[4];
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k >> d1 >> d2;
    x2[0] = (k + d2 - d1) / 3;
    x3[0] = x2[0] - d2;
    x1[1] = x2[0] + d1;
    x2[1] = (k - (d1 + d2)) / 3;
    x3[1] = x2[1] + d2;
    x1[1] = x2[1] + d1;
    x2[2] = (k + d1 + d2) / 3;
    x3[2] = x2[2] - d2;
    x1[2] = x2[2] - d1;
    x2[3] = (k + d1 - d2) / 3;
    x3[3] = x2[3] + d2;
    x1[3] = x2[3] - d1;
    int sucess = 0;
    for (int j = 0; j < 4; j++) {
      if (x1[j] < 0 || x1[j] > k) continue;
      if (x2[j] < 0 || x2[j] > k) continue;
      if (x3[j] < 0 || x3[j] > k) continue;
      if (x1[j] + x2[j] + x3[j] != k) continue;
      long long max_x = max(x1[j], max(x2[j], x3[j]));
      long long req = (max_x - x1[j]) + (max_x - x2[j]) + (max_x - x3[j]);
      if (n - k >= req && (n - k - req) % 3 == 0) sucess = 1;
    }
    if (sucess)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
