#include <bits/stdc++.h>
using namespace std;
int i, j, n, k, tot, ans, sum, b, t, head, tail, x;
int h[100005];
bool f[1000005], g1[100005], g2[100005];
string st;
char ch;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    if (ch == '-')
      g1[i] = true;
    else
      g1[i] = false;
  }
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    if (ch == '-')
      g2[i] = true;
    else
      g2[i] = false;
  }
  memset(f, false, sizeof f);
  int T = 1;
  int en = 1;
  head = 0;
  tail = 1;
  h[1] = 1;
  f[1] = true;
  while (T <= n) {
    while (head != tail) {
      head++;
      head %= 100000;
      x = h[head];
      if (x > n) {
        if (x == 2 * n) {
          cout << "YES" << endl;
          return 0;
        }
        if (x + k > 2 * n) {
          cout << "YES" << endl;
          return 0;
        }
        if (!f[x + 1] && g2[x - n + 1]) {
          f[x + 1] = true;
          en++;
          en %= 100000;
          h[en] = x + 1;
        }
        if (!f[x - 1] && g2[x - n - 1] && (x - n - 1) > T) {
          f[x - 1] = true;
          en++;
          en %= 100000;
          h[en] = x - 1;
        }
        if (!f[x - n + k] && g1[x - n + k]) {
          f[x - n + k] = true;
          en++;
          en %= 100000;
          h[en] = x - n + k;
        }
      } else {
        if (x == n) {
          cout << "YES" << endl;
          return 0;
        }
        if (x + k > n) {
          cout << "YES" << endl;
          return 0;
        }
        if (!f[x + 1] && g1[x + 1]) {
          f[x + 1] = true;
          en++;
          en %= 100000;
          h[en] = x + 1;
        }
        if (!f[x - 1] && g1[x - 1] && (x - 1 > T)) {
          f[x - 1] = true;
          en++;
          en %= 100000;
          h[en] = x - 1;
        }
        if (!f[x + n + k] && g2[x + k]) {
          f[x + n + k] = true;
          en++;
          en %= 100000;
          h[en] = x + n + k;
        }
      }
    }
    tail = en;
    T++;
  }
  cout << "NO" << endl;
}
