#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
long long n, m;
char a[N];
int main() {
  cin >> n >> m;
  string st;
  cin >> st;
  int k = 0;
  for (int i = 1; i < m; i++) {
    a[i] = k;
    k++;
  }
  if (st == "YES") {
    a[m] = k;
  } else {
    a[m] = a[1];
  }
  for (int i = 2; i <= n - m + 1; i++) {
    string st;
    cin >> st;
    if (st == "YES") {
      a[i + m - 1] = k;
      k++;
    } else {
      a[i + m - 1] = a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] < 26) {
      cout << char(a[i] + 'A') << " ";
    } else {
      cout << char(a[i] - 26 + 'A') << "a ";
    }
  }
  return 0;
}
