#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
  int n = s.size();
  bool a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++)
    if (s[i] >= '0' && s[i] <= '9')
      a = 1;
    else if (s[i] >= 'a' && s[i] <= 'z')
      b = 1;
    else
      c = 1;
  int k = (int)a + (int)b + (int)c;
  if (k == 3) return 1;
  return 0;
}
int main() {
  int n, a[200005], f, x;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x >> f;
  vector<int> a1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= x) {
      continue;
    }
    ans += (a[i] / (x + f));
    if (a[i] % (x + f) > x) ans++;
  }
  cout << (long long)ans * (long long)f;
  return 0;
}
