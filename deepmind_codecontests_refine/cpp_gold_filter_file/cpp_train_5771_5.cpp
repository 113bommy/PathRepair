#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return p * x;
}
const int max_int = (int)1e9 + 227 + 1;
const int max_n = (int)1e6 + 227 + 1;
const int mod = (int)1e9 + 7;
struct BOR {
  int link[2];
  int k;
  long long sum;
} new_bor;
vector<BOR> t[2];
void add(int type, int y, int kek) {
  int v = 0;
  for (int i = 30; i >= -1; i--) {
    t[type][v].k += kek;
    t[type][v].sum += y * kek;
    if (i == -1) break;
    bool bit = (1 << i) & y;
    if (t[type][v].link[bit] == 0) {
      t[type][v].link[bit] = t[type].size();
      t[type].push_back(new_bor);
    }
    v = t[type][v].link[bit];
  }
}
void add(int type, vector<int> a) {
  for (int i = 0; i < a.size(); i++) add(type, a[i], 1);
}
void del(int type, vector<int> a) {
  for (int i = 0; i < a.size(); i++) add(type, a[i], -1);
}
long long get(int type, int c) {
  int v = 0;
  if (t[type][v].k < c) return (long long)2e18;
  long long ans = 0;
  long long e = 0;
  for (int i = 30; i >= 0; i--) {
    if (t[type][v].link[0] == 0) {
      t[type][v].link[0] = t[type].size();
      t[type].push_back(new_bor);
    }
    if (t[type][v].link[1] == 0) {
      t[type][v].link[1] = t[type].size();
      t[type].push_back(new_bor);
    }
    if (t[type][v].k == c) return t[type][v].sum + ans;
    if (t[type][t[type][v].link[0]].k >= c) {
      v = t[type][v].link[0];
    } else {
      ans += t[type][t[type][v].link[0]].sum;
      c -= t[type][t[type][v].link[0]].k;
      e += (1 << i);
      v = t[type][v].link[1];
    }
  }
  return ans + e * c;
}
long long get_ans(int i, int all) {
  int j = all - i;
  return get(0, i) + get(1, j);
}
int main() {
  int n = next_int<int>();
  int m = next_int<int>();
  t[0].push_back(new_bor);
  t[1].push_back(new_bor);
  int mda = 1;
  vector<vector<int> > a(n + 1);
  for (int i = 0; i < n; i++) {
    int x = next_int<int>();
    int y = next_int<int>();
    add(1, y, 1);
    if (x >= n) mda++;
    if (x <= n) a[x].push_back(y);
  }
  long long ans = (long long)2e18;
  add(0, a[n]);
  del(1, a[n]);
  if (n - 1 >= 0) add(0, a[n - 1]), del(1, a[n - 1]);
  for (int i = n; i >= 0; i--) {
    if (i - 1 >= 0) mda += a[i - 1].size();
    int l = max(max(0, mda - m), i - t[1][0].k);
    int r = min(t[0][0].k, i);
    while (r - l > 1) {
      int c = (l + r) / 2;
      if ((c == max(max(0, mda - m), i - t[1][0].k)) ||
          (get_ans(c, i) <= get_ans(c - 1, i)))
        l = c;
      else
        r = c;
    }
    if (l <= r) {
      ans = min(ans, get_ans(l, i));
      ans = min(ans, get_ans(r, i));
    }
    if (i <= n) del(0, a[i]), add(1, a[i]);
    if (i - 2 >= 0) add(0, a[i - 2]), del(1, a[i - 2]);
  }
  if (ans == (long long)2e18) ans = -1;
  cout << ans << "\n";
}
