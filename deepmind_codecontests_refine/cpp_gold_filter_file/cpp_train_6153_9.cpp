#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, a, b, ch, k1c, k2c, k1x, k1y, k2x, k2y;
  bool t1, t2;
  queue<int> qx;
  queue<int> qy;
  cin >> n >> d;
  cin >> ch;
  vector<string> vec(ch);
  for (int i = 0; i < ch; i++) {
    while (!qx.empty()) qx.pop();
    while (!qy.empty()) qy.pop();
    cin >> k1c >> k2c;
    k1x = 0;
    k1y = d;
    k2x = n;
    k2y = n - d;
    for (int j = 0; j < n + 1; j++) {
      if (abs(k1c - k1x) == abs(j - k1y) || abs(k1c - k2x) == abs(j - k2y))
        qx.push(j);
      if (abs(j - k1x) == abs(k2c - k1y) || abs(j - k2x) == abs(k2c - k2y))
        qy.push(j);
    }
    if (k2c >= qx.front() && k2c <= qx.back()) t1 = true;
    if (k1c >= qy.front() && k1c <= qy.back()) t2 = true;
    if (t1 && t2)
      vec[i] = "YES";
    else
      vec[i] = "NO";
    t1 = false;
    t2 = false;
  }
  for (int i = 0; i < ch; i++) cout << vec[i] << endl;
}
