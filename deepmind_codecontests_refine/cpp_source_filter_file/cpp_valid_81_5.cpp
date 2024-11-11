#include <bits/stdc++.h>
using namespace std;
int di[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dj[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int mod = 1e9 + 7;
int INF = 1E9;
long long INFF = 1E18;
int const N = 3e5 + 5;
int a[N];
int n;
int go(int i, bool first, int second) {
  if (i == n) return (!second ? 0 : 1e9);
  long long x = a[i];
  if ((i % 2 && !first) || ((i % 2 == 0 && first))) x *= -1;
  return min(go(i + 1, first, second + x), go(i + 1, !first, second) + 1);
}
int pre[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> n >> k;
    long long ss = 0;
    for (int i = 0; i < n; ++i) {
      char x;
      cin >> x;
      if (x == '-')
        a[i] = -1;
      else
        a[i] = 1;
      if ((a[i] == 1 && i % 2 == 0) || (i % 2 && a[i] == -1))
        ss++;
      else
        ss--;
      pre[i + 1] = ss;
    }
    while (k--) {
      int l, r;
      cin >> l >> r;
      long long sum = (pre[r] - pre[l - 1]);
      int xx = !sum ? 0 : (sum + 1) % 2 + 1;
      cout << xx << "\n";
    }
  }
}
