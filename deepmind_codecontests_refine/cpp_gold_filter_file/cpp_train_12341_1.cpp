#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1e9 + 7;
int64_t n;
int64_t x[100000 + 1];
int64_t y[100000 + 1];
int64_t z[100000 + 1];
int64_t a[2];
int64_t b[2];
int64_t c[2];
int64_t abc[2];
int64_t r;
int64_t mx, my, mz;
int64_t ansx, ansy, ansz;
bool verify() {
  int64_t temp = mx + my + mz;
  if (abc[0] <= temp && temp <= abc[1]) {
    return 1;
  }
  return 0;
}
void output1() {
  ansx = (my + mz + r);
  ansy = (mx + mz + r);
  ansz = (my + mx + r);
  return;
}
bool check1() {
  int64_t temp = mx + my + mz;
  if (temp <= abc[1]) {
    return 1;
  }
  return 0;
}
void findsol(int64_t d) {
  mx = a[0];
  my = b[0];
  mz = c[0];
  if (verify()) {
    output1();
    return;
  }
  mx = a[1];
  if (!check1()) {
    mx -= (mx + my + mz - abc[1]);
    output1();
    return;
  }
  mx = a[1];
  my = b[1];
  if (!check1()) {
    my -= (mx + my + mz - abc[1]);
    output1();
    return;
  }
  my = b[1];
  mz = c[1];
  if (!check1()) {
    mz -= (mx + my + mz - abc[1]);
    output1();
    return;
  }
  mz = c[1];
  output1();
  return;
}
bool valid(int64_t d) {
  abc[0] = (-1 * d) + x[1] + y[1] + z[1];
  abc[1] = d + x[1] + y[1] + z[1];
  a[0] = (-1 * d) - x[1] + y[1] + z[1];
  a[1] = d - x[1] + y[1] + z[1];
  b[0] = (-1 * d) + x[1] - y[1] + z[1];
  b[1] = d + x[1] - y[1] + z[1];
  c[0] = (-1 * d) + x[1] + y[1] - z[1];
  c[1] = d + x[1] + y[1] - z[1];
  for (int i = 2; i < n + 1; i++) {
    abc[0] = max(abc[0], (-1 * d) + x[i] + y[i] + z[i]);
    abc[1] = min(abc[1], d + x[i] + y[i] + z[i]);
    a[0] = max(a[0], (-1 * d) - x[i] + y[i] + z[i]);
    a[1] = min(a[1], d - x[i] + y[i] + z[i]);
    b[0] = max(b[0], (-1 * d) + x[i] - y[i] + z[i]);
    b[1] = min(b[1], d + x[i] - y[i] + z[i]);
    c[0] = max(c[0], (-1 * d) + x[i] + y[i] - z[i]);
    c[1] = min(c[1], d + x[i] + y[i] - z[i]);
  }
  int64_t t[8];
  t[0] = a[0];
  t[1] = a[1];
  t[2] = b[0];
  t[3] = b[1];
  t[4] = c[0];
  t[5] = c[1];
  t[6] = abc[0];
  t[7] = abc[1];
  for (r = 1; r >= 0; r--) {
    a[0] = t[0];
    a[1] = t[1];
    b[0] = t[2];
    b[1] = t[3];
    c[0] = t[4];
    c[1] = t[5];
    abc[0] = t[6];
    abc[1] = t[7];
    a[0] -= r;
    a[1] -= r;
    b[0] -= r;
    b[1] -= r;
    c[0] -= r;
    c[1] -= r;
    abc[0] -= (3 * r);
    abc[1] -= (3 * r);
    if (a[0] % 2 == 0) {
      a[0] /= 2;
    } else {
      if (a[0] <= 0) {
        a[0] /= 2;
      } else {
        a[0] = (a[0] + 1) / 2;
      }
    }
    if (b[0] % 2 == 0) {
      b[0] /= 2;
    } else {
      if (b[0] <= 0) {
        b[0] /= 2;
      } else {
        b[0] = (b[0] + 1) / 2;
      }
    }
    if (c[0] % 2 == 0) {
      c[0] /= 2;
    } else {
      if (c[0] <= 0) {
        c[0] /= 2;
      } else {
        c[0] = (c[0] + 1) / 2;
      }
    }
    if (abc[0] % 2 == 0) {
      abc[0] /= 2;
    } else {
      if (abc[0] <= 0) {
        abc[0] /= 2;
      } else {
        abc[0] = (abc[0] + 1) / 2;
      }
    }
    if (a[1] % 2 == 0) {
      a[1] /= 2;
    } else {
      if (a[1] >= 0) {
        a[1] /= 2;
      } else {
        a[1] = (a[1] - 1) / 2;
      }
    }
    if (b[1] % 2 == 0) {
      b[1] /= 2;
    } else {
      if (b[1] >= 0) {
        b[1] /= 2;
      } else {
        b[1] = (b[1] - 1) / 2;
      }
    }
    if (c[1] % 2 == 0) {
      c[1] /= 2;
    } else {
      if (c[1] >= 0) {
        c[1] /= 2;
      } else {
        c[1] = (c[1] - 1) / 2;
      }
    }
    if (abc[1] % 2 == 0) {
      abc[1] /= 2;
    } else {
      if (abc[1] >= 0) {
        abc[1] /= 2;
      } else {
        abc[1] = (abc[1] - 1) / 2;
      }
    }
    if (a[0] > a[1]) {
      continue;
    }
    if (b[0] > b[1]) {
      continue;
    }
    if (c[0] > c[1]) {
      continue;
    }
    if (abc[0] > abc[1]) {
      continue;
    }
    int64_t temp1 = a[0] + b[0] + c[0];
    int64_t temp2 = a[1] + b[1] + c[1];
    if ((temp1 <= abc[1] && temp1 >= abc[0]) ||
        (temp2 <= abc[1] && temp2 >= abc[0]) ||
        (temp1 <= abc[0] && temp2 >= abc[1])) {
      return 1;
    }
  }
  return 0;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
      cin >> x[i] >> y[i] >> z[i];
    }
    int64_t left = -1;
    int64_t right =
        3 * int64_t(1000 * 1000 * 1000) * int64_t(1000 * 1000 * 1000) + 10;
    int64_t mid;
    while (right - left > 1) {
      mid = (left + right) / 2;
      if (valid(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    valid(right);
    findsol(right);
    cout << ansx << " " << ansy << " " << ansz << '\n';
  }
}
