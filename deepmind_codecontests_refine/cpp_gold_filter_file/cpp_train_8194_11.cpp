#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return l + rng() % (r - l + 1); }
const int N = 210;
int n, ret;
int a[N], cnt[N], fre[N];
int f[N][N];
int main() {
  n = ({
    int x = 0;
    int c = getchar(), n = 0;
    for (; !isdigit(c); c = getchar()) n = (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    n ? -x : x;
  });
  for (int i = 1, _c = n * 2; i <= _c; ++i) {
    a[i] = ({
      int x = 0;
      int c = getchar(), n = 0;
      for (; !isdigit(c); c = getchar()) n = (c == '-');
      for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
      n ? -x : x;
    });
    cnt[a[i]]++;
    for (int j = 1, _c = n; j <= _c; ++j)
      if (j != a[i]) f[a[i]][j] += cnt[j];
  }
  for (int i = 1, _c = n * 2; i <= _c; ++i)
    if (!fre[a[i]]) {
      for (int j = 1, _c = n; j <= _c; ++j)
        if (!fre[j]) ret += f[a[i]][j];
      fre[a[i]] = 1;
    }
  cout << ret;
}
