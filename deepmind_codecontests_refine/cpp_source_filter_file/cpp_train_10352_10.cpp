#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const int MAXN = 2 * 1000 * 1000;
const int MAXD = 30;
int nn;
pair<int, int> num[MAXN];
int a[MAXN], q[MAXN], fen[MAXN];
long long rev[30][2];
int pos[30];
int fen_sum(int x) {
  int ans = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
    ans += fen[i];
  }
  return ans;
}
int fen_inc(int x, int val) {
  for (int i = x; i < nn; i += (i | (i + 1))) {
    fen[i] += val;
  }
  return 0;
}
int main() {
  int deg_n;
  scanf("%d", &deg_n);
  int n = (1 << deg_n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &q[i]);
  }
  for (int i = 1; i <= deg_n; ++i) {
    nn = (1 << i);
    for (int j = 0; j < n; j += nn) {
      for (int k = 0; k < nn; ++k) {
        num[k] = make_pair(a[j + k], k);
      }
      sort(num, num + nn);
      long long sum = (((long long)nn) * (nn - 1)) / 2;
      int cur_n = 1;
      for (int k = 1; k < nn; ++k) {
        if (num[k].first == num[k - 1].first) {
          cur_n++;
        } else {
          sum -= (((long long)cur_n) * (cur_n - 1)) / 2;
          cur_n = 1;
        }
      }
      sum -= (((long long)cur_n) * (cur_n - 1)) / 2;
      for (int k = 0; k < nn; ++k) {
        fen[k] = 0;
      }
      long long cur_rev = 0;
      for (int k = 0; k < nn; ++k) {
        cur_rev += k - fen_sum(num[k].second - 1);
        fen_inc(num[k].second, 1);
      }
      rev[i][0] += cur_rev;
      rev[i][1] += sum - cur_rev;
    }
  }
  for (int i = deg_n; i > 0; --i) {
    rev[i][0] = rev[i][0] - rev[i - 1][0];
    rev[i][1] = rev[i][1] - rev[i - 1][1];
  }
  for (int i = 0; i <= deg_n; ++i) {
    pos[i] = 0;
  }
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    ans = 0;
    for (int j = 1; j <= q[i]; ++j) {
      pos[j] = 1 - pos[j];
    }
    for (int j = 1; j <= deg_n; ++j) {
      ans += rev[j][pos[j]];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
