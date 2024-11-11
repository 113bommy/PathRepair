#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
struct node {
  int l, r;
  int d;
};
node dp[maxn];
int k, x, n, m;
void Init(int l1, int r1, int l2, int r2) {
  dp[1].l = l1, dp[1].r = r1;
  dp[2].l = l2, dp[2].r = r2;
  dp[1].d = 0;
  dp[2].d = 0;
  for (int i = 3; i <= k; i++) {
    dp[i].l = dp[i - 2].l;
    dp[i].r = dp[i - 1].r;
    dp[i].d = dp[i - 2].d + dp[i - 1].d;
    if (dp[i - 2].r == 0 && dp[i - 1].l == 2) {
      dp[i].d++;
    }
  }
}
bool judge(int x, int l, int r, int len) {
  if (l == 0 && r == 2) {
    if (len == 2 && x == 0) {
      return false;
    }
    if (len / 2 >= x) {
      return true;
    }
  } else if (l == 0 || r == 2) {
    if ((len - 1) / 2 >= x) {
      return true;
    }
  } else {
    if ((len - 2) / 2 >= x) {
      return true;
    }
  }
  return false;
}
void OutPut(int x, int l, int r, int len) {
  if (len == 1) {
    cout << char(l + 'A') << endl;
    return;
  }
  if (l == 0 && r == 2) {
    int i = 1;
    cout << char(l + 'A');
    if (x) {
      cout << 'C';
      i++;
      x--;
    }
    while (x) {
      cout << "AC";
      x--;
      i += 2;
    }
    while (i < len) {
      cout << 'C';
      i++;
    }
  } else if (l == 0) {
    int i = 1;
    cout << char(l + 'A');
    if (x) {
      cout << 'C';
      i++;
      x--;
    }
    while (x) {
      cout << "AC";
      x--;
      i += 2;
    }
    while (i < len - 1) {
      cout << 'C';
      i++;
    }
    cout << char(r + 'A');
  } else if (r == 2) {
    int i = 1;
    cout << char(l + 'A');
    while (x) {
      cout << "AC";
      x--;
      i += 2;
    }
    while (i < len) {
      cout << 'C';
      i++;
    }
  } else {
    int i = 1;
    cout << char(l + 'A');
    while (x) {
      cout << "AC";
      x--;
      i += 2;
    }
    while (i < len - 1) {
      cout << 'C';
      i++;
    }
    cout << char(r + 'A');
  }
  cout << endl;
}
void Solve() {
  int i;
  for (i = 0; i < 81; i++) {
    int l[2] = {i % 3, (i / 3) % 3}, r[2] = {(i / 9) % 3, (i / 27) % 3};
    if (n == 1 && l[0] != r[0]) {
      continue;
    }
    if (m == 1 && l[1] != r[1]) {
      continue;
    }
    Init(l[0], r[0], l[1], r[1]);
    x -= dp[k].d;
    if (x >= 0) {
      long long a[maxn];
      for (int o = 0; o <= n / 2; o++) {
        for (int p = 0; p <= m / 2; p++) {
          a[1] = o, a[2] = p;
          for (int q = 3; q <= k; q++) {
            a[q] = a[q - 1] + a[q - 2];
          }
          if (a[k] == x && judge(o, l[0], r[0], n) && judge(p, l[1], r[1], m)) {
            OutPut(o, l[0], r[0], n);
            OutPut(p, l[1], r[1], m);
            return;
          } else if (a[k] > x) {
            break;
          }
        }
      }
    }
    x += dp[k].d;
  }
  if (i == 81) {
    cout << "Happy new year!" << endl;
  }
}
int main() {
  while (cin >> k >> x >> n >> m) {
    Solve();
  }
  return 0;
}
