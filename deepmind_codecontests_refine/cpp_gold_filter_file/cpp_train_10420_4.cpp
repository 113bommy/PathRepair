#include <bits/stdc++.h>
using namespace std;
bool a[100052], b[100050];
int c[100050];
int main() {
  int pp = 0, ppp = 0;
  for (int i = 0; i < 100050; i++) {
    a[i] = false;
    b[i] = false;
  }
  int n, x;
  cin >> n >> x;
  int tem;
  for (int i = 0; i < n; i++) {
    cin >> tem;
    c[i] = tem;
    if (a[tem] == true) {
      cout << 0;
      return 0;
    } else
      a[tem] = true;
  }
  for (int i = 0; i < n; i++) {
    tem = c[i] & x;
    if (a[tem] == true && tem != c[i]) {
      pp = 1;
    }
    if (b[tem] == true) {
      ppp = 2;
    } else
      b[tem] = true;
  }
  if (pp == 1)
    cout << 1;
  else if (ppp == 2)
    cout << 2;
  else
    cout << -1;
  return 0;
}
