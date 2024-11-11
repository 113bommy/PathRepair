#include <bits/stdc++.h>
using namespace std;
int boys[110];
int girls[110];
int main() {
  int n, m, b, j, i, g, k, l;
  cin >> n >> m;
  cin >> b;
  while (b--) {
    cin >> j;
    boys[j] = 1;
  }
  cin >> g;
  while (g--) {
    cin >> j;
    girls[g] = 1;
  }
  for (i = 0; i < 1000000; i++) {
    k = i % n;
    l = i % m;
    if (boys[k] == 1) {
      girls[l] = 1;
    }
    if (girls[l] == 1) {
      boys[k] = 1;
    }
  }
  int flag = 1;
  for (i = 0; i < n; i++) {
    if (boys[i] == 0) {
      flag = 0;
      break;
    }
  }
  for (i = 0; i < m; i++) {
    if (girls[i] == 0) {
      flag = 0;
      break;
    }
  }
  if (flag == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
