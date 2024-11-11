#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n, m, q;
int a[1005][1005], op, x, y;
int h_up[1005][1005], h_down[1005][1005], h_left[1005][1005],
    h_right[1005][1005];
void update(int x, int y) {
  a[x][y] = 1 - a[x][y];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i][y] == 0) {
      h_up[i][y] = 0;
      cnt = 0;
    } else {
      cnt++;
      h_up[i][y] = cnt;
    }
  }
  cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i][y] == 0) {
      cnt = 0;
      h_down[i][y] = 0;
    } else {
      cnt++;
      h_down[i][y] = cnt;
    }
  }
  cnt = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (a[x][i] == 0) {
      cnt = 0;
      h_right[x][i] = 0;
    } else {
      cnt++;
      h_right[x][i] = cnt;
    }
  }
  cnt = 0;
  for (int i = 0; i < m; i++) {
    if (a[x][i] == 0) {
      cnt = 0;
      h_left[x][i] = 0;
    } else {
      cnt++;
      h_left[x][i] = cnt;
    }
  }
}
int sz;
int le[1005], ri[1005], h[1005];
int calc_up(int x, int y) {
  sz = m;
  for (int i = 0; i < sz; i++) h[i] = h_up[x][i];
  int ans = 0;
  int l = y, r = y;
  for (int i = h[y]; i > 0; i--) {
    while (l >= 0 && h[l] >= i) l--;
    while (r < sz && h[r] >= i) r++;
    ans = max(ans, i * (r - l - 1));
  }
  return ans;
}
int calc_down(int x, int y) {
  sz = m;
  for (int i = 0; i < sz; i++) h[i] = h_down[x][i];
  int ans = 0;
  int l = y, r = y;
  for (int i = h[y]; i > 0; i--) {
    while (l >= 0 && h[l] >= i) l--;
    while (r < sz && h[r] >= i) r++;
    ans = max(ans, i * (r - l - 1));
  }
  return ans;
}
int calc_left(int x, int y) {
  sz = n;
  for (int i = 0; i < sz; i++) h[i] = h_left[i][y];
  int ans = 0;
  int l = y, r = y;
  for (int i = h[y]; i > 0; i--) {
    while (l >= 0 && h[l] >= i) l--;
    while (r < sz && h[r] >= i) r++;
    ans = max(ans, i * (r - l - 1));
  }
  return ans;
}
int calc_right(int x, int y) {
  sz = n;
  for (int i = 0; i < sz; i++) h[i] = h_right[i][y];
  int ans = 0;
  int l = y, r = y;
  for (int i = h[y]; i > 0; i--) {
    while (l >= 0 && h[l] >= i) l--;
    while (r < sz && h[r] >= i) r++;
    ans = max(ans, i * (r - l - 1));
  }
  return ans;
}
int calc(int x, int y) {
  int up1 = calc_up(x, y);
  int down1 = calc_down(x, y);
  int left1 = calc_left(x, y);
  int right1 = calc_right(x, y);
  return max(up1, max(down1, max(left1, right1)));
}
void show() {
  cout << "This is array:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i][j];
    cout << endl;
  }
  cout << "This is h_up:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << h_up[i][j];
    cout << endl;
  }
  cout << "This is h_down:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << h_down[i][j];
    cout << endl;
  }
  cout << "This is h_left:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << h_left[i][j];
    cout << endl;
  }
  cout << "This is h_right:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << h_right[i][j];
    cout << endl;
  }
  cout << endl;
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0)
        cnt = 0;
      else
        cnt++;
      h_left[i][j] = cnt;
    }
    cnt = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (a[i][j] == 0)
        cnt = 0;
      else
        cnt++;
      h_right[i][j] = cnt;
    }
  }
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == 0)
        cnt = 0;
      else
        cnt++;
      h_up[i][j] = cnt;
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i][j] == 0)
        cnt = 0;
      else
        cnt++;
      h_down[i][j] = cnt;
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> op >> x >> y;
    x--;
    y--;
    if (op == 1) {
      update(x, y);
    } else
      cout << calc(x, y) << endl;
  }
  return 0;
}
