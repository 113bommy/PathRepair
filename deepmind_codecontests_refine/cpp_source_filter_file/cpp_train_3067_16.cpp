#include <bits/stdc++.h>
using namespace std;
struct Lines {
  string s1;
  string s2;
};
Lines mass[101];
int main() {
  int n, sum = 1;
  bool flag = true;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> mass[i].s1 >> mass[i].s2;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if ((mass[i].s1 == mass[j].s1) && (mass[i].s2 == mass[j].s2)) {
        flag = false;
        break;
      }
    }
    if (flag) ++sum;
    flag = true;
  }
  cout << sum;
  return 0;
}
