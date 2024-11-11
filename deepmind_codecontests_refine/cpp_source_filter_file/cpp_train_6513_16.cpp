#include <bits/stdc++.h>
using namespace std;
int n, a, b, k, len, mx[1000005];
char s[1000005];
vector<int> ans;
struct el {
  int st, dr;
  bool operator<(const el &A) const { return dr - st + 1 < A.dr - A.st + 1; }
} v[1000005];
int main() {
  int i, j, p = 1, p1;
  cin >> n >> a >> b >> k >> (s + 1);
  while (p <= n) {
    for (; p <= n && s[p] == '1'; ++p)
      ;
    if (p > n) continue;
    for (p1 = p; p1 <= n && s[p1] == '0'; ++p1)
      ;
    --p1;
    ++len;
    v[len].st = p;
    v[len].dr = p1;
    p = p1 + 1;
  }
  sort(v + 1, v + len + 1);
  for (i = n; i; --i) mx[i] = mx[i + 1] + (v[i].dr - v[i].st + 1) / b;
  for (i = 1; i <= n; ++i)
    if (mx[i + 1] >= a) {
      for (j = v[i].st + b - 1; j <= v[i].dr; j += b) ans.push_back(j);
    } else {
      a -= mx[i + 1];
      int lungime = v[i].dr - v[i].st + 1, poz = v[i].st + b - 1;
      while (lungime >= a * b) {
        ans.push_back(poz);
        poz += b;
        lungime -= b;
      }
      break;
    }
  cout << ans.size() << "\n";
  for (auto it : ans) cout << it << " ";
  cout << "\n";
  return 0;
}
