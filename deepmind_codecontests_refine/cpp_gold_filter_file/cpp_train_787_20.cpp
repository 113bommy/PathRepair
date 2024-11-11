#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int n;
bool in_range(int x) { return x >= 0 && x < n; }
int main() {
  ios::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  n = a.size();
  int ia = 0, ja = n / 2 + n % 2;
  ja--;
  int ib = ja + 1, jb = n - 1;
  int i = 0, j = n - 1;
  string res(n, '.');
  for (int k = 0; k < n; k++) {
    if (k % 2 == 0) {
      if (k == n - 1 || a[ia] < b[jb]) {
        res[i++] = a[ia++];
      } else
        res[j--] = a[ja--];
    } else {
      if (k == n - 1 || b[jb] > a[ia])
        res[i++] = b[jb--];
      else
        res[j--] = b[ib++];
    }
  }
  cout << res;
  return 0;
}
