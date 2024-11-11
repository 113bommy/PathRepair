#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, z;
};
int n, a[1001][1001], b[10001];
vector<node> v;
int main() {
  int br = 0, i, j, x, y, in, mx, c;
  node el;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    a[x][y] = 1;
  }
  for (i = 1; i <= n; i++)
    for (j = n; j >= 1; j--)
      if (a[i][j]) {
        b[i] = j;
        break;
      }
  for (i = n; i >= 1; i--) {
    mx = -1;
    for (j = 1; j <= n; j++)
      if (b[j] > mx || mx == -1) {
        mx = b[j];
        c = j;
      }
    b[c] = 0;
    swap(b[c], b[i]);
    if (c != i) {
      for (j = 1; j <= n; j++) swap(a[i][j], a[c][j]);
      el.x = 1;
      el.y = i;
      el.z = c;
      v.push_back(el);
      br++;
    }
  }
  for (j = 1; j <= n; j++) {
    for (i = 1; i <= n; i++)
      if (a[i][j]) break;
    if (i == n + 1) {
      in = j;
    }
  }
  for (i = 1; i <= n; i++) b[i] = 10000;
  for (j = 1; j <= n; j++)
    for (i = 1; i <= n; i++)
      if (a[i][j]) {
        b[j] = i;
        break;
      }
  for (j = 1; j < n; j++) {
    mx = -1;
    if (in != j) {
      br++;
      el.x = 2;
      el.y = j;
      el.z = in;
      v.push_back(el);
    }
    swap(b[in], b[j]);
    in = j;
    for (i = j; i <= n; i++)
      if (b[i] < mx || mx == -1) {
        mx = b[i];
        c = i;
      }
    if (in != c) {
      br++;
      el.x = 2;
      el.y = in;
      el.z = c;
      v.push_back(el);
    }
    b[c] = 1000001;
    swap(b[in], b[c]);
    in = c;
  }
  cout << br << endl;
  int sz = v.size();
  for (i = 0; i < sz; i++)
    cout << v[i].x << ' ' << v[i].y << ' ' << v[i].z << endl;
}
