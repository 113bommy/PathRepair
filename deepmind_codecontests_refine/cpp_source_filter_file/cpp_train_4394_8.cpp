#include <bits/stdc++.h>
using namespace std;
const int N = 4e5;
const int oo = 1e9 + 5;
int du[] = {-1, 0, 0, 1};
int dv[] = {0, -1, 1, 0};
const long long mod = 1e9 + 7;
long long sqr(long long x) { return x * x; }
int getbit(int state, int i) { return ((state >> i) & 1); }
int dem, n, k;
string s;
bool ok[N + 5];
char ans[N + 5];
int vt(int x) {
  if (x >= n) return x - n;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  cin >> s;
  s += s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      if (s[i - 1] == 'W' && s[i + 1] == 'W') ok[i] = true;
    } else {
      if (s[i - 1] == 'B' && s[i + 1] == 'B') ok[i] = true;
    }
  }
  for (int i = n + 1; i < 2 * n; i++) ok[i] = ok[i - n];
  ok[0] = ok[n];
  for (int i = 1; i <= n; i++) dem += ok[i];
  if (dem == n) {
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        if (k % 2)
          cout << 'W';
        else
          cout << 'B';
      } else {
        if (k % 2)
          cout << 'B';
        else
          cout << 'W';
      }
    }
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (!ok[i]) {
      int dem = 0, j = i + 1;
      while (ok[j]) {
        dem++;
        j++;
      }
      if (dem > 2 * k) {
        for (int g = i + 1; g <= i + k; g++) ans[vt(g)] = s[i];
        for (int g = j - 1; g >= j - k; g--) ans[vt(g)] = s[i];
        for (int g = i + k + 1; g < j - k; g++) {
          if (s[vt(g)] == 'B') {
            if (k % 2)
              ans[vt(g)] = 'W';
            else
              ans[vt(g)] = 'B';
          } else {
            if (k % 2)
              ans[vt(g)] = 'B';
            else
              ans[vt(g)] = 'W';
          }
        }
      } else {
        for (int g = i + 1; g <= (i + j) / 2; g++) ans[vt(g)] = s[i];
        for (int g = (i + j) / 2 + 1; g < j; g++) ans[vt(g)] = s[j];
      }
      ans[vt(i)] = s[i];
      ans[vt(j)] = s[j];
      i = j - 1;
    }
  for (int i = 0; i < n; i++) cout << ans[i];
  return 0;
}
