#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000;
int main() {
  int n, m, x, t;
  vector<int> a;
  vector<int> p;
  vector<int> q;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> t >> x;
    x--;
    while (!q.empty() && q[q.size() - 1] <= x) {
      q.pop_back();
      p.pop_back();
    }
    q.push_back(x);
    p.push_back(t);
  }
  vector<int> b;
  for (int i = 0; i < q[0] + 1; i++) b.push_back(a[i]);
  sort(b.begin(), b.end());
  int r = q[0], l = 0;
  for (int i = 0; i < q.size() - 1; i++) {
    for (int j = q[i]; j > q[i + 1]; j--) {
      if (p[i] == 1) {
        a[j] = b[r];
        r--;
      } else {
        a[j] = b[l];
        l++;
      }
    }
  }
  for (int i = q[q.size() - 1]; i >= 0; i--)
    if (p[q.size() - 1] == 1) {
      a[i] = b[r];
      r--;
    } else {
      a[i] = b[l];
      l++;
    }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  return 0;
}
