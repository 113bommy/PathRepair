#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
const ll MODBASE = 1000000007LL;
const int MAXN = 100010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;
int res1[MAXN], res2[MAXN];
void process(int n) {
  if (n <= 0) return;
  int u = 0;
  while ((1 << u) <= n) u++;
  u--;
  int i = 1;
  while ((1 << u) + i - 1 <= n) {
    res1[(1 << u) + i - 1] = (1 << u) - i;
    res1[(1 << u) - i] = (1 << u) + i - 1;
    i++;
  }
  process((1 << u) - i);
}
void solve1(int n) {
  if (n % 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  process(n);
  for (int i = (1); i <= (n); i++) cout << res1[i] << ' ';
  cout << "\n";
}
void solve2(int n) {
  if (n <= 5) {
    cout << "NO\n";
    return;
  }
  int u = 0;
  while ((1 << u) <= n) u++;
  u--;
  if ((1 << u) == n) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (n == 6) {
    cout << "3 6 2 5 1 4\n";
    return;
  }
  if (n == 7) {
    cout << "7 3 6 2 5 1 4\n";
    return;
  }
  cout << "7 3 6 2 5 1 4 ";
  for (int i = (3); i <= (u); i++) {
    int last = min(n, (1 << (i + 1)) - 1);
    int x = (1 << i);
    for (int j = (x); j <= (last); j++) {
      int p = j + 1;
      if (p > last) p = x;
      cout << p << ' ';
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  solve1(n);
  solve2(n);
  return 0;
}
