#include <bits/stdc++.h>
using namespace std;
int f[500001], b[500001], a[500001];
int N, A, B, T;
int FIXED;
int fnc(int mid) {
  int i;
  int p, q, t;
  for (i = 0; i < mid; i++) {
    p = (f[i] + (i)*A);
    q = (b[mid - 1 - i] + (mid - i - 1) * A);
    p = p + q + FIXED;
    q = p;
    p = p + (i)*A;
    q = q + (mid - i - 1) * A;
    t = min(p, q);
    if (t <= T) return 1;
  }
  return 0;
}
int main() {
  int i, j;
  cin >> N >> A >> B >> T;
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'w') {
      a[i + 1] = B + 1;
    } else {
      a[i + 1] = 1;
    }
    if (i == 0) {
      FIXED = a[i + 1];
    } else {
      f[i] = (a[i + 1] + f[i - 1]);
    }
  }
  j = 1;
  for (i = s.size(); i > 0; i--) {
    b[j] = (a[i] + b[j - 1]);
    j++;
  }
  int l = 0, h = N, mid, check;
  while (l <= h) {
    mid = (l + h) / 2;
    if (fnc(mid)) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  cout << max(0, l - 1) << endl;
  return 0;
}
