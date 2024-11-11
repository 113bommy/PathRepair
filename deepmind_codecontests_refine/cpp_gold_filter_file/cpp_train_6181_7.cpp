#include <bits/stdc++.h>
using namespace std;
const int size = 410000, mod = 1000000009, inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nex[2][4] = {0, 1, 0, -1, 1, 0, -1, 0};
long long ar[size], x;
vector<int> bnum[80];
int a[80][size], sol[size], last, p[80], n;
void cl() { memset(a[last], 0, sizeof(int) * (n + 1)); }
void de() {
  cout << "------------------" << endl;
  for (int i = 0; i < last + 1; i++) {
    for (int j = 0; j < n + 1; j++) cout << a[i][j] << ' ';
    cout << endl;
  }
  cout << "------------------" << endl;
}
void pr(long long x) {
  for (int i = 63; i >= 0; i--) cout << (x >> i & 1);
  cout << endl;
}
void check() {
  int i, j, k;
  bool flag = 0;
  for (i = 0; i < last; i++)
    if (a[last][p[i]])
      for (j = p[i]; j <= n; j++) a[last][j] ^= a[i][j];
  for (i = 0; i < n; i++)
    if (a[last][i]) {
      flag = 1, p[last] = i;
      break;
    }
  if (flag) last++;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i], x ^= ar[i];
    for (int j = 0; j < 64; j++)
      if (1ll << j & ar[i]) bnum[j].push_back(i);
  }
  for (int i = 63; i >= 0; i--) {
    if (~x & 1ll << i) {
      cl();
      for (int j = 0; j < bnum[i].size(); j++) a[last][bnum[i][j]] = 1;
      a[last][n] = 1;
      check();
    }
  }
  for (int i = 63; i >= 0; i--) {
    if (x & 1ll << i) {
      cl();
      for (int j = 0; j < bnum[i].size(); j++) a[last][bnum[i][j]] = 1;
      check();
    }
  }
  for (int i = 0; i < last; i++) {
    int id = min_element(p + i, p + last) - p;
    for (int j = 0; j <= n; j++) swap(a[i][j], a[id][j]);
    swap(p[i], p[id]);
  }
  for (int i = last - 1; i >= 0; i--) {
    sol[p[i]] = a[i][n];
    for (int j = p[i] + 1; j < n; j++) sol[p[i]] ^= a[i][j] * sol[j];
  }
  for (int i = 0; i < n; i++) cout << (sol[i] ? 1 : 2) << ' ';
  cout << endl;
  return 0;
}
