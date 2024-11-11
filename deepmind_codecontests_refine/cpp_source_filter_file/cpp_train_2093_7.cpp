#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10, MAXN = 100;
int a[MAXN];
int n;
bool is_right(int sum) {
  int s1(0);
  int kol(0);
  for (int i = 0; i < n; i++) {
    s1 += a[i];
    if (s1 == sum) {
      s1 = 0;
      kol++;
    }
    if (s1 > sum) {
      return false;
    }
  }
  if (kol == 1) {
    return false;
  }
  if (!s1)
    return true;
  else
    return false;
}
signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  for (int i = 0; i < MAXN; i++) {
    if (is_right(i)) {
      cout << "YES";
      exit(0);
    }
  }
  cout << "NO";
  return 0;
}
