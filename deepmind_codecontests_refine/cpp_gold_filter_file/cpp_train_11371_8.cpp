#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int s;
string ac[3000];
int num[3000];
int main() {
  cin >> n >> m >> k;
  s = 4 * n * m - 2 * n - 2 * m;
  if (k > s) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if (m == 1) {
    if (k > (n - 1)) {
      cout << 2 << endl;
      cout << n - 1 << ' ' << "D" << endl;
      cout << k - (n - 1) << ' ' << "U" << endl;
    } else {
      cout << 1 << endl;
      cout << k << ' ' << "D" << endl;
    }
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (m > 1) {
        ac[cnt] = "R";
        num[cnt++] = m - 1;
      }
    } else {
      if (m > 1) {
        ac[cnt] = "R";
        num[cnt++] = m - 1;
      }
      ac[cnt] = "UD";
      num[cnt++] = 1;
    }
    if (i == n - 1) {
      if (m > 1) {
        ac[cnt] = "L";
        num[cnt++] = m - 1;
      }
      if (n > 1) {
        ac[cnt] = "U";
        num[cnt++] = n - 1;
      }
    } else {
      if (m > 2) {
        ac[cnt] = "LDU";
        num[cnt++] = m - 2;
      }
      ac[cnt] = "LD";
      num[cnt++] = 1;
    }
  }
  int sum = 0;
  for (int i = 0; i < cnt; i++) {
    sum += num[i] * ac[i].size();
    if (sum >= k) {
      sum -= num[i] * ac[i].size();
      int need = k - sum;
      int d = need / ac[i].size(), e = need % ac[i].size();
      int add = 0;
      if (d > 0) add++;
      if (e > 0) add++;
      cout << i + add << endl;
      for (int j = 0; j < i; j++) {
        cout << num[j] << ' ' << ac[j] << endl;
      }
      if (d > 0) {
        cout << d << ' ' << ac[i] << endl;
      }
      if (e > 0) {
        cout << 1 << ' ';
        for (int j = 0; j < e; j++) cout << ac[i][j];
        cout << endl;
      }
      return 0;
    }
  }
  return 0;
}
