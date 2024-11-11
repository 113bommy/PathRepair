#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
const long long mod = 1e9 + 7;
vector<string> a(N);
vector<string> b(N);
long long flag = 0;
long long n;
vector<string> rotatex(vector<string> a) {
  auto bx = a;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) bx[j][i] = a[i][j];
  for (auto &x : bx) reverse(x.begin(), x.end());
  return bx;
}
void printx(vector<string> a) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cout << a[i][j];
    cout << endl;
  }
}
int32_t main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (long long i = 0; i < 4; i++) cin >> a[i];
  for (long long i = 0; i < 4; i++) cin >> b[i];
  if (a == b) flag = 1;
  for (long long rot = 0; rot < 4; rot++) {
    a = rotatex(a);
    if (a == b) flag = 1;
  }
  for (auto &x : a) reverse(x.begin(), x.end());
  for (long long rot = 0; rot < 4; rot++) {
    a = rotatex(a);
    if (a == b) flag = 1;
  }
  for (long long i = 0; i < n / 2; i++) swap(a[i], a[n - i - 1]);
  for (long long rot = 0; rot < 4; rot++) {
    a = rotatex(a);
    if (a == b) flag = 1;
  }
  if (flag)
    cout << "Yes";
  else
    cout << "No";
}
