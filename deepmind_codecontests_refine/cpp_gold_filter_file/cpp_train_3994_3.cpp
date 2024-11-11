#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long n, m;
int x = -1, y = -1;
bool check(int mi) {
  int h = 0;
  int c[100005] = {0};
  int d = 0;
  for (int i = 1; i <= mi; i++) {
    c[a[i]]++;
    if (c[a[i]] == 1) d++;
    if (d == m) {
      if (x == -1 && y == -1) {
        x = 1, y = i;
        return true;
      } else if (y - x + 1 > i)
        x = 1, y = i;
      h = 1;
    }
  }
  for (int i = mi + 1; i <= n; i++) {
    c[a[i - mi]]--;
    if (c[a[i - mi]] == 0) d--;
    c[a[i]]++;
    if (c[a[i]] == 1) d++;
    if (d == m) {
      if (x == -1 && y == -1)
        x = i - mi + 1, y = i;
      else if (y - x + 1 > mi)
        x = i - mi + 1, y = i;
      h = 1;
    }
  }
  return h;
}
int main() {
  cin >> n >> m;
  int i, j;
  for (i = 1; i <= n; i++) cin >> a[i];
  int l = 1, r = n;
  int m;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m))
      r = m - 1;
    else
      l = m + 1;
  }
  cout << x << " " << y << endl;
  return 0;
}
