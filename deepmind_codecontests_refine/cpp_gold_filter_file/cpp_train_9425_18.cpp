#include <bits/stdc++.h>
using namespace std;
long long n, k;
double a[100007];
string st;
void openFile() { freopen("input.txt", "r", stdin); }
void solve() {
  bool ok = false;
  int c = 0;
  cin >> n >> k;
  n++;
  for (int i = n; i >= 1; i--) {
    cin >> st;
    if (st[0] == '?') {
      if (i == n) ok = true;
    } else {
      c++;
      a[i] = stod(st);
    }
  }
  if (k == 0) {
    if (ok) {
      if (c % 2 == 1) {
        cout << "Yes";
        return;
      }
      cout << "No";
      return;
    }
    if (a[n] == 0) {
      cout << "Yes";
      return;
    } else {
      cout << "No";
      return;
    }
  }
  if (c < n) {
    if (n % 2 == 0) {
      cout << "Yes";
      return;
    } else {
      cout << "No";
      return;
    }
  }
  for (int i = 2; i <= n; i++) {
    a[i] += a[i - 1] * k;
  }
  if (a[n] == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
int main() {
  solve();
  return 0;
}
