#include <bits/stdc++.h>
using namespace std;
const int MAX = 12;
long long p[MAX];
int t[MAX];
int a, b;
bool marque[MAX];
long long n, m, ans;
long long g(long long n) {
  for (int i = MAX - 1; i >= 0; i--)
    if (p[i] <= n) return i + 1;
  return 1;
}
void f(int x) {
  if (x == a + b) {
    long long v1 = 0, v2 = 0;
    for (int i = 0; i < a; i++) v1 += p[i] * t[i];
    for (int i = a; i < a + b; i++) v2 += p[i - a] * t[i];
    ans += (v1 <= n && v2 <= m);
    return;
  }
  for (int i = 0; i < 7; i++)
    if (!marque[i]) {
      marque[i] = 1;
      t[x] = i;
      f(x + 1);
      marque[i] = 0;
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  p[0] = 1;
  for (int i = 1; i < MAX; i++) p[i] = p[i - 1] * 7;
  cin >> n >> m;
  --n;
  --m;
  if ((a = g(n)) + (b = g(m)) > 7) {
    cout << 0 << '\n';
    return 0;
  }
  f(0);
  cout << ans << '\n';
  return 0;
}
