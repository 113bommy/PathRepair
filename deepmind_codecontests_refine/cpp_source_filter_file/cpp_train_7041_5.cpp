#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int arr = 2e5 + 10;
const int ar = 2e3 + 10;
const long double pi = acos(-1);
const long double eps = 1e-10;
const long long md = 1e9 + 7;
int a[arr];
int p[arr];
int min_val1[(int)(5000 + 10)][(int)(5000 + 10)];
int min_val2[(int)(5000 + 10)][(int)(5000 + 10)];
int cnt_left[arr];
vector<int> cur;
inline bool check1(int l, int r) {
  int min_val = min_val1[l][r];
  int val = min_val - (l == 0 ? 0 : p[l - 1]) - (l == 0 ? 0 : cnt_left[l - 1]);
  if (val >= 0) {
    return 1;
  } else {
    return 0;
  }
}
inline bool check2(int l, int r) {
  int min_val = min_val2[l][r];
  int val =
      min_val - (l == 0 ? 0 : p[l - 1]) + 0 + (l == 0 ? 0 : cnt_left[l - 1]);
  if (val >= 0) {
    return 1;
  } else {
    return 0;
  }
}
inline bool check22(int l, int r, int m, int val1) {
  int min_val = min_val2[m + 1][r];
  int val = min_val - (l == 0 ? 0 : p[l - 1]) + val1 + cnt_left[m];
  if (val >= 0) {
    return 1;
  } else {
    return 0;
  }
}
int get(int l, int r) {
  if ((r - l + 1) % 2 != 0) {
    return 0;
  }
  int cnt1 = cnt_left[r] - (l == 0 ? 0 : cnt_left[l - 1]);
  int sum = p[r] - (l == 0 ? 0 : p[l - 1]);
  if (abs(sum) > cnt1) {
    return 0;
  }
  int m = (cnt1 - sum) / 2;
  if (m == 0) {
    if (check2(l, r)) {
      return 1;
    } else {
      return 0;
    }
  } else if (cur[m - 1] == r) {
    if (check1(l, r)) {
      return 1;
    } else {
      return 0;
    }
  } else {
    m = cur[m - 1];
    if (check1(l, m) &&
        check22(l, r, m, cnt_left[m] - (l == 0 ? 0 : cnt_left[l - 1]))) {
      return 1;
    } else {
      return 0;
    }
  }
}
int main() {
  string s;
  cin >> s;
  int n = (int)(s.size());
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      a[i] = 1;
    } else if (s[i] == ')') {
      a[i] = -1;
    } else {
      a[i] = 0;
    }
    cnt_left[i] = (i == 0 ? 0 : cnt_left[i - 1]) + (a[i] == 0);
    p[i] = (i == 0 ? 0 : p[i - 1]) + a[i];
  }
  for (int i = 0; i < n; i++) {
    int val = 2e9;
    for (int j = i; j < n; j++) {
      val = min(val, p[i] + cnt_left[i]);
      min_val1[i][j] = val;
    }
  }
  for (int i = 0; i < n; i++) {
    int val = 2e9;
    for (int j = i; j < n; j++) {
      val = min(val, p[i] - cnt_left[i]);
      min_val2[i][j] = val;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cur.clear();
    for (int j = i; j < n; j++) {
      if (a[j] == 0) {
        cur.push_back(j);
      }
      ans += get(i, j);
    }
  }
  cout << ans << "\n";
}
