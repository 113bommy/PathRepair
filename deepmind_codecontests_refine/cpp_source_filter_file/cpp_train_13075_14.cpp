#include <bits/stdc++.h>
const long long oo = 0x3f3f3f3f;
const int _cnt = 1000 * 1000;
const int _p = 1000 * 1000 * 1000 + 7;
long long o(long long x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
using namespace std;
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int n, m, ans = 0, x, y;
string s, t;
int get_ans(int k) {
  int ans = 0;
  for (int i = 0; i < n; i++) ans += (s[i + 1] == t[k + i]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  cin.ignore();
  cin >> s;
  cin.ignore();
  cin >> t;
  s = ' ' + s;
  t = ' ' + t;
  for (int i = 1; i <= m - n + 1; i++) {
    int y = get_ans(i);
    if (y > ans) {
      ans = y;
      x = i;
    }
  }
  cout << n - ans << endl;
  for (int i = 1; i <= n; i++)
    if (s[i] != t[i + x - 1]) printf("%d ", i);
  return 0;
}
