#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MXN = 1e6 + 7;
const int N = 1e3 + 7;
long long n;
long long a[MXN], t[4 * MXN], to[4 * MXN];
string s;
void push(long long v, long long L, long long R) {
  if (to[v]) {
    t[v] += to[v];
    to[v + v] += to[v];
    to[v + v + 1] += to[v];
    to[v] = 0;
  }
}
void build(long long v, long long l, long long r) {
  if (l == r) {
    t[v] = a[l];
  } else {
    long long mid = (l + r) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
long long getmin(long long v, long long tl, long long tr, long long l,
                 long long r) {
  push(v, tl, tr);
  if (l > tr || tl > r) {
    return INF;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  long long mid = (tl + tr) / 2;
  return min(getmin(v * 2, tl, mid, l, r),
             getmin(v * 2 + 1, mid + 1, tr, l, r));
}
void upd(long long v, long long tl, long long tr, long long l, long long r,
         long long val) {
  push(v, l, r);
  if (l > tr || tl > r) return;
  if (l <= tl && tr <= r) {
    to[v] += val;
    push(v, l, r);
    return;
  }
  long long mid = (tl + tr) / 2;
  upd(v * 2, tl, mid, l, r, val);
  upd(v * 2 + 1, mid + 1, tr, l, r, val);
  t[v] = min(t[v * 2], t[v * 2 + 1]);
}
long long pw(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y % 2) ret *= x;
    x *= x;
    y /= 2;
  }
  return ret;
}
void solve(string v) {
  long long x = 0;
  vector<long long> arr;
  long long sz = 0;
  string s = ' ' + v;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '-') {
      x *= -1;
    }
    if (s[i] == ' ') {
      arr.push_back(x);
      x = 0;
      sz = 0;
    }
    if (s[i] != ' ' && s[i] != '-') {
      if (s[i] == '0') {
        sz++;
      } else {
        x += ((s[i] - 48) * pw(10, sz));
        sz++;
      }
    }
  }
  if (arr.size() == 2) {
    long long l = arr[1], r = arr[0];
    if (l > r) {
      cout << min(getmin(1, 1, n, 1, r + 1), getmin(1, 1, n, l + 1, n)) << "\n";
    } else {
      cout << getmin(1, 1, n, l + 1, r + 1) << "\n";
    }
  }
  if (arr.size() == 3) {
    long long l = arr[2], r = arr[1], x = arr[0];
    if (l > r) {
      upd(1, 1, n, l + 1, n, x);
      upd(1, 1, n, 1, r + 1, x);
    } else {
      upd(1, 1, n, l + 1, r + 1, x);
    }
  }
  arr.clear();
}
int main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  build(1, 1, n);
  long long M;
  scanf("%I64d\n", &M);
  string num;
  for (int i = 1; i <= M; i++) {
    getline(cin, num);
    solve(num);
  }
  return 0;
}
