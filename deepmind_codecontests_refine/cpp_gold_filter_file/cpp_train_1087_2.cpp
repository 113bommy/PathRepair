#include <bits/stdc++.h>
using namespace std;
int m[1000] = {0};
int tmp[1000] = {0}, ans[1001] = {0};
int main() {
  bool yes = false;
  int n, index = 0, q = 0, qw = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
    if (m[i] != 0) {
      index++;
      tmp[index] = m[i];
    }
  }
  if (n == 1) {
    cout << m[1];
    return 0;
  }
  if (index == 0) {
    cout << '0';
    return 0;
  }
  for (int i = 1; i <= index; i++)
    if (tmp[i] < 0) q++;
  if (q % 2 == 0) {
    for (int i = 1; i <= index; i++) cout << tmp[i] << ' ';
    yes = true;
  } else {
    int maxi = -699944;
    for (int i = 1; i <= index; i++) {
      if (tmp[i] > maxi && tmp[i] < 0) {
        maxi = tmp[i];
        qw = i;
      }
    }
    if (index - 1 == 0) {
      cout << "0";
      return 0;
    }
    for (int i = 1; i <= index; i++)
      if (i != qw) cout << tmp[i] << ' ';
    yes = true;
  }
  return 0;
}
