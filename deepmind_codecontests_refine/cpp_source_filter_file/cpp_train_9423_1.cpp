#include <bits/stdc++.h>
using namespace std;
int res[500050] = {0};
int res1[500050] = {0};
int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += res[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, int val, int N) {
  while (idx <= N) {
    res[idx] += val;
    idx += (idx & -idx);
  }
}
int read1(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += res1[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update1(int idx, int val, int N) {
  while (idx <= N) {
    res1[idx] += val;
    idx += (idx & -idx);
  }
}
int main() {
  int n, k, a, b, q;
  int t;
  int d, ai, p;
  int check, check1;
  cin >> n >> k >> a >> b >> q;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> d >> ai;
      check = read(d) - read(d - 1);
      check1 = read1(d) - read1(d - 1);
      if (check < a) {
        if (check + ai <= a) {
          update(d, ai, n);
        } else {
          update(d, a - check, n);
        }
      }
      if (check1 < b) {
        if (check1 + ai <= b) {
          update1(d, ai, n);
        } else {
          update1(d, b - check1, n);
        }
      }
    }
    if (t == 2) {
      cin >> p;
      int post = 0;
      int pre = 0;
      if (p + k - 1 < n) {
        post = read(n) - read(p + k - 1);
      }
      pre = read1(p) - read1(1);
      cout << pre + post << "\n";
    }
  }
}
