#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
struct Block {
  char let;
  long long len;
};
bool operator==(const Block &x, const Block &y) {
  return (x.let == y.let) && (x.len == y.len);
}
bool operator<=(const Block &x, const Block &y) {
  return (x.let == y.let) && (x.len <= y.len);
}
int n, m;
vector<int> pi(N, 0);
Block a[N], b[N];
long long ans = 0LL;
void unite(Block *a, int &n) {
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (m == 0 || a[m - 1].let != a[i].let) {
      a[m++] = a[i];
    } else {
      a[m - 1].len += a[i].len;
    }
  }
  n = m;
  return;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int l;
    char sp, x;
    cin >> l >> sp >> x;
    a[i].let = x, a[i].len = l;
  }
  for (int i = 0; i < m; i++) {
    int l;
    char sp, x;
    cin >> l >> sp >> x;
    b[i].let = x, b[i].len = l;
  }
  unite(a, n);
  unite(b, m);
  if (m == 1) {
    for (int i = 0; i < n; i++) {
      if (b[0] <= a[i]) {
        ans += (a[i].len - b[0].len + 1);
      }
    }
    cout << ans << '\n';
    return 0;
  }
  if (m == 2) {
    for (int i = 0; i < n - 1; i++) {
      if (b[0] <= a[i] && b[1] <= a[i + 1]) {
        ans++;
      }
    }
    cout << ans << '\n';
    return 0;
  }
  auto buildPi = [&](void) {
    pi[1] = 0;
    for (int i = 2; i < m - 1; i++) {
      int j = pi[i - 1];
      while (j > 0 && !(b[j + 1] == b[i])) {
        j = pi[j];
      }
      if (b[j + 1] == b[i]) {
        j++;
      }
      pi[i] = j;
    }
  };
  buildPi();
  for (int i = 1, j = 0; i < n - 1; i++) {
    while (j > 0 && !(b[j + 1] == a[i])) {
      j = pi[j];
    }
    if (b[j + 1] == a[i]) {
      j++;
    }
    if (j == m - 2) {
      if (b[0] <= a[i - j] && b[j + 1] <= a[i + 1]) {
        ans++;
      }
      j = pi[j];
    }
  }
  cout << ans << '\n';
  return 0;
}
