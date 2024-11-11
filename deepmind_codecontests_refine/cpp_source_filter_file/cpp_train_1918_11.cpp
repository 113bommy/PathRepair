#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, a, b;
  cin >> n >> m >> i >> j >> a >> b;
  vector<int> cor;
  cor.push_back(1);
  cor.push_back(1);
  cor.push_back(n);
  cor.push_back(1);
  cor.push_back(1);
  cor.push_back(m);
  cor.push_back(n);
  cor.push_back(m);
  bool flag = 0;
  int res = 987654321;
  for (unsigned int k = 0; k < cor.size(); k += 2) {
    int x, y;
    x = abs(cor[k] - i);
    y = abs(cor[k + 1] - j);
    if (x % a != 0 or y % b != 0) continue;
    x = x / a;
    y = y / b;
    if (abs(x - y) % 2 != 0) continue;
    res = min(res, max(x, y));
  }
  if ((i + a > n && i - a < 0 && res != 0) ||
      (res != 0 && j + b > m && j - b < 0))
    res = 987654321;
  if (res == 987654321)
    cout << "Poor Inna and pony!" << endl;
  else
    cout << res << endl;
  return 0;
}
