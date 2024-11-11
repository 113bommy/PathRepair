#include <bits/stdc++.h>
using namespace std;
inline void minimize(int &x, int y) { x = min(x, y); }
inline void maximize(int &x, int y) { x = max(x, y); }
const int N = 2000 + 1067;
int n, k, t, res;
int rr[N], rr1[N], x[N];
void add(int i, int t) {
  ++res, rr[res] = i;
  for (int j = i + 1; j <= n; j++)
    if (x[j] != t) {
      rr1[res] = j;
      break;
    }
  int l, r;
  l = i;
  r = rr1[res];
  while (l < r) {
    swap(x[l], x[r]);
    r--;
    l++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  for (int test = 1; test <= t; test++) {
    cin >> n >> k;
    res = 0;
    int cur = 0;
    int rem = (n - 2 * (k - 1)) / 2;
    for (int i = 1; i <= n; i++) {
      char s;
      cin >> s;
      if (s == ')')
        x[i] = -1;
      else
        x[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      int t = x[i];
      if (cur == 0) {
        if (t == -1) {
          add(i, -1);
        }
        cur = 1;
      } else {
        if (k > 1) {
          if (t == 1) add(i, 1);
          cur = 0;
          --k;
        } else {
          if (cur < rem) {
            if (t == -1) add(i, -1);
            cur++;
          } else if (t == 1)
            add(i, 1);
        }
      }
    }
    cout << res << endl;
    for (int i = 1; i <= res; i++) cout << rr[i] << " " << rr1[i] << endl;
  }
  return 0;
}
