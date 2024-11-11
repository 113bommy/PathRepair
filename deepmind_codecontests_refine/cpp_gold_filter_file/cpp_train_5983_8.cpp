#include <bits/stdc++.h>
using namespace std;
int f[100001], a[100001], n, p;
string s;
int Dis(char c, char c1) { return min(abs(c - c1), 26 - abs(c - c1)); }
int main() {
  ios::sync_with_stdio(false);
  ifstream inf("input.txt");
  cin >> n >> p;
  p--;
  cin >> s;
  for (int i = 0; i <= n / 2 - 1; i++)
    if (s[i] != s[n - i - 1]) {
      f[i] = 1;
      f[n - i - 1] = 1;
    }
  int r = -1, r1 = -1, u = -1, u1 = -1;
  for (int i = 0; i <= n / 2 - 1; i++)
    if (f[i]) {
      if (r == -1) r = i;
      r1 = i;
    }
  for (int i = (n + 1) / 2; i <= n - 1; i++)
    if (f[i]) {
      if (u == -1) u = i;
      u1 = i;
    }
  if (u1 == -1) {
    cout << 0;
    return 0;
  }
  int ans1 = 0, ans3 = 0;
  for (int i = (n + 1) / 2; i <= n - 1; i++)
    if (f[i]) {
      a[i] = Dis(s[i], s[n - i - 1]);
      ans1 += a[i];
      ans3 += a[i];
    }
  ans3 += min(abs(u1 - p), abs(u - p)) + abs(u1 - u);
  ans1 += n - p + (n / 2 + 1);
  for (int i = 0; i <= n / 2 - 1; i++)
    if (f[i]) a[i] = max(Dis(s[n - i - 1], s[i]) - Dis(s[i], s[n - i - 1]), 0);
  int j = 0, k = 10000000;
  for (int i = n / 2 - 1; i >= 0; i--) {
    j += a[i];
    k = min(k, j + (n / 2 - i));
  }
  ans1 += k;
  memset(a, 0, sizeof(a));
  int ans2 = 0, ans4 = 0;
  for (int i = 0; i <= n / 2 - 1; i++)
    if (f[i]) {
      a[i] = Dis(s[i], s[n - i - 1]);
      ans2 += a[i];
      ans4 += a[i];
    }
  ans4 += min(abs(r1 - p), abs(r - p)) + abs(r1 - r);
  ans2 += p - 1 + (n / 2 + 1);
  for (int i = (n + 1) / 2; i <= n - 1; i++)
    if (f[i]) a[i] = max(Dis(s[n - i - 1], s[i]) - Dis(s[i], s[n - i - 1]), 0);
  int j1 = 0, k1 = 10000000;
  for (int i = n - 1; i >= (n + 1) / 2; i--) {
    j1 += a[i];
    k1 = min(k1, j1 + (i - n / 2));
  }
  ans2 += k1;
  cout << min(min(min(ans1, ans2), ans3), ans4);
}
