#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
map<int, int> m, ma;
int n;
int a[maxn];
int calc(int val) {
  int &ans = m[val];
  if (ans == 0) {
    set<int> s;
    for (int i = 0; i <= 32; i++) {
      int num = (val & ((1 << i) - 1)) | (val >> (i + 1));
      if (num == val) break;
      s.insert(num);
    }
    int dd[40];
    memset(dd, 0, sizeof(dd));
    for (auto x : s) dd[calc(x)] = 1;
    for (int i = 0; i <= 32; i++)
      if (dd[i] == 0) {
        ans = i;
        break;
      }
    if (ans == 0) ans = -1;
  }
  if (ans == -1) return 0;
  return ans;
}
int main() {
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 2; j <= sqrt(a[i]); j++) {
      if (a[i] % j) continue;
      int cnt = 0;
      while (a[i] % j == 0) {
        a[i] /= j;
        cnt++;
      }
      ma[j] |= (1 << cnt);
    }
    if (a[i] != 1) ma[a[i]] |= 1;
  }
  m[0] = -1;
  m[1] = 1;
  for (auto x : ma) ans ^= calc(x.second);
  if (ans)
    cout << "Mojtaba";
  else
    cout << "Arpa";
  return 0;
}
