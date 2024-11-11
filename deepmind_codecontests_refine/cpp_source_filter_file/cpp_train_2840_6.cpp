#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, ccnt, pos = 0, sum = 0, minn2 = INT_MAX, sum2, cnt2 = 0,
                            cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0,
                            vis[100005], x1, y7, x2, y2, x3, y3, aaa, bbb;
long long a[1000005], b[1000005], c[1000005], c2[1000005], c3[1000005],
    c4[1000005], kk[1000005], cnt = 0, x, y, z, d = 0, minn = LONG_LONG_MAX,
                              maxx = -LONG_LONG_MAX;
long long pos1 = 3, pos2 = 3, tem, tem2, l, r, ans = 0, ans2, mod = 1000000007,
          tw[105], th[105], dd, ee, out[1000005];
string s1, s2, s;
char cc[1005][1005], ch;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  tw[0] = 1;
  for (int i = 1; i <= 30; i++) {
    tw[i] = tw[i - 1] * 2;
  }
  cin >> n;
  cnt5 = 0;
  for (int i = 0;; i++) {
    if (tw[i] >= n) {
      pos = i;
      break;
    }
  }
  for (int i = 0; i < 24; i++) {
    a[cnt5] = n * tw[i];
    b[cnt5] = 1;
    c[cnt5] = n * tw[i];
    cnt5++;
  }
  a[cnt5] = n;
  b[cnt5] = 2;
  c[cnt5] = n * tw[pos - 1];
  x = a[cnt5] ^ c[cnt5];
  cnt5++;
  for (int i = 0; i <= 23; i++) {
    a[cnt5] = x * tw[i];
    b[cnt5] = 1;
    c[cnt5] = x * tw[i];
    cnt5++;
  }
  for (int i = 1; i <= 2 * n; i++) {
    if ((x * i) % (2 * n) == 1) {
      pos1 = i;
      pos2 = (x * i - 1) / (2 * n);
      aaa = x * i;
      bbb = x * i - 1;
    }
  }
  d = 0;
  for (int i = 24; i >= 0; i--) {
    if (pos1 >= tw[i]) {
      if (d == 0) {
        d = 1;
        ans = x * tw[i];
      } else {
        a[cnt5] = ans;
        b[cnt5] = 1;
        c[cnt5] = x * tw[i];
        cnt5++;
        ans = ans + x * tw[i];
      }
      pos1 = pos1 - tw[i];
    }
  }
  ans = 0;
  d = 0;
  for (int i = 24; i >= 0; i--) {
    if (pos2 >= tw[i]) {
      if (d == 0) {
        d = 1;
        ans = 2 * n * tw[i];
      } else {
        a[cnt5] = ans;
        b[cnt5] = 1;
        c[cnt5] = 2 * n * tw[i];
        cnt5++;
        ans = ans + 2 * n * tw[i];
      }
      pos2 = pos2 - tw[i];
    }
  }
  a[cnt5] = aaa;
  b[cnt5] = 2;
  c[cnt5] = bbb;
  cnt5++;
  cout << cnt5 << '\n';
  for (int i = 0; i < cnt5; i++) {
    cout << a[i] << " ";
    if (b[i] == 1) {
      cout << "+ ";
    } else {
      cout << "^ ";
    }
    cout << c[i] << '\n';
  }
}
