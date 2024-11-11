#include <bits/stdc++.h>
using namespace std;
int n, m, k, step = 0, l = -1;
vector<int> sl;
vector<string> res;
void case1() {
  res.push_back("R");
  sl.push_back(0);
  l++;
  for (int i = 1; i < m; i++) {
    if (k == 0) break;
    k--;
    sl[l]++;
  }
  if (k == 0) return;
  res.push_back("L");
  sl.push_back(0);
  l++;
  for (int i = 1; i < m; i++) {
    if (k == 0) break;
    k--;
    sl[l]++;
  }
}
void case2() {
  int y;
  for (int i = 2; i <= n; i++) {
    if (k <= 0) return;
    res.push_back("D");
    sl.push_back(1), l++, k--;
    if (k == 0) return;
    if (m > 1) {
      res.push_back("R"), sl.push_back(0), l++;
      for (int i = 1; i < m; i++) {
        if (k == 0) return;
        y = i;
        k--;
        sl[l]++;
      }
    }
    if (k >= 3 && m > 1) {
      res.push_back("UDL"), sl.push_back(0), l++;
      for (int i = m; i > 1; i--) {
        y = i - 1;
        if (k >= 3) {
          sl[l]++;
          k -= 3;
        }
      }
    }
    if (k == 2 && m > 1 && y != 1)
      res.push_back("UD"), sl.push_back(1), l++, k = k - 2;
    if (k == 1 && m > 1 && y != 1)
      res.push_back("L"), sl.push_back(1), l++, k = k - 1;
  }
  if (k > 0) {
    res.push_back("U"), sl.push_back(0), l++;
    for (int i = n; i >= 1; i--) {
      if (k == 0) return;
      k--;
      sl[l]++;
    }
  }
}
void output() {
  cout << l + 1 << endl;
  for (int i = 0; i <= l; i++) cout << sl[i] << " " << res[i] << endl;
}
int main() {
  cin >> n >> m >> k;
  if (n * m * 4 - 2 * n - 2 * m < k) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  if (m > 1) case1();
  if (k > 0) case2();
  output();
}
