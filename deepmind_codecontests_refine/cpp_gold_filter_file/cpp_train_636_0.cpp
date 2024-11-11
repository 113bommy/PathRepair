#include <bits/stdc++.h>
using namespace std;
long long n, mx[256], aux[256], ans = 0, inf = 1e9;
string s;
void count(long long mx[]) {
  long long in = 0, cn = 0;
  for (int c : s) {
    if (in != c) {
      mx[in] = max(mx[in], cn);
      in = c;
      cn = 0;
    }
    cn++;
  }
  mx[in] = max(mx[in], cn);
}
void update() {
  cin >> s;
  long long pre = 0, suf = 0;
  for (int i = 0; i < s.size() && s[0] == s[i]; i++) pre++;
  for (int i = s.size() - 1; i + 1 && s.back() == s[i]; i--) suf++;
  if (pre == s.size()) {
    for (int i = 'a'; i <= 'z'; i++)
      if (i == s[0]) {
        mx[i] = mx[i] + pre * (mx[i] + 1);
      } else {
        mx[i] = int(mx[i] > 0);
      }
  } else {
    memset(aux, 0, sizeof(aux));
    if (s[0] == s.back()) {
      if (mx[s[0]]) aux[s[0]] = suf + pre + 1;
    } else {
      aux[s[0]] = pre + int(mx[s[0]] > 0);
      aux[s.back()] = suf + int(mx[s.back()] > 0);
    }
    count(aux);
    for (int i = 'a'; i <= 'z'; i++)
      mx[i] = max((long long)(mx[i] > 0), aux[i]);
  }
  for (int i = 'a'; i <= 'z'; i++) mx[i] = min(mx[i], inf);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  count(mx);
  n--;
  while (n--) update();
  for (int i = 'a'; i <= 'z'; i++) ans = max(ans, mx[i]);
  cout << ans << '\n';
  return 0;
}
