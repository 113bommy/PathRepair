#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 5], p[1000000 + 5];
int get_sum(int l, int r) {
  if (l > r) {
    return 0;
  }
  return (l % 2 == 1) ? p[r] - p[l - 1] : p[l - 1] - p[r];
}
int check_elimination(int l, int r, int m) {
  return ((m - l + 1) % 2 == 1) ? get_sum(l, m - 1) + get_sum(m + 1, r)
                                : get_sum(l, m - 1) - get_sum(m + 1, r);
}
int get_sign(int m) { return m > 0 ? 1 : -1; }
int calculate_odd_segment(int l, int r) {
  if (l == r) {
    return l;
  }
  int pos = 0;
  int lb = l;
  int rb = r;
  while (rb - lb > 1) {
    int mb = (lb + rb) / 2;
    int lq = check_elimination(l, r, lb);
    int mq = check_elimination(l, r, mb);
    int rq = check_elimination(l, r, rb);
    if (lq == 0) {
      pos = lb;
      break;
    }
    if (mq == 0) {
      pos = mb;
      break;
    }
    if (rq == 0) {
      pos = rb;
      break;
    }
    if (lq * mq > 0) {
      lb = mb;
    } else {
      rb = mb;
    }
  }
  return pos;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string ss;
    cin >> ss;
    for (int i = 1; i <= n; i++) {
      a[i] = (ss[i - 1] == '+' ? 1 : -1);
    }
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] + (i % 2 == 1 ? a[i] : -a[i]);
    }
    for (int o = 0; o < q; o++) {
      int l, r;
      cin >> l >> r;
      if (get_sum(l, r) == 0) {
        cout << "0\n";
        continue;
      }
      bool even = false;
      if ((r - l + 1) % 2 == 0) {
        even = true;
        l++;
      }
      int pos = calculate_odd_segment(l, r);
      if (even) {
        cout << "2\n" << l - 1 << " " << pos << '\n';
      } else {
        cout << "1\n" << pos << '\n';
      }
    }
  }
}
