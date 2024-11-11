#include <bits/stdc++.h>
using namespace std;
long long readInt() {
  bool minus = false;
  long long result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
long long exp(long long taban, long long us) {
  long long carpan = taban % 1000000007;
  long long temp = us;
  long long res = 1;
  while (temp) {
    if (temp % 2) res = (res * carpan) % 1000000007;
    temp /= 2;
    carpan = (carpan * carpan) % 1000000007;
  }
  return res;
}
long long ebob(long long a, long long b) {
  if (!a) return b;
  return ebob(b % a, a);
}
long long ekok(long long a, long long b) { return (a * b) / ebob(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<vector<int>>> cnt(
      26, vector<vector<int>>(26, vector<int>(5005, 0)));
  double count[26] = {};
  for (int i = 0; i < n; i++) s[i] -= 'a';
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < (n + i + 1); j++) {
      if (j < n)
        cnt[s[i]][s[j]][j - i]++;
      else
        cnt[s[i]][s[j - n]][j - i]++;
    }
    count[s[i]]++;
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    bool check = false;
    double tmp[5005] = {};
    for (int j = 1; j < n; j++) {
      for (char u = 0; u < 25; u++) {
        if (cnt[c][u][j] == 1) tmp[j]++;
      }
    }
    double mx = 0;
    for (int j = 1; j < n; j++) {
      mx = max(mx, tmp[j] / count[c]);
    }
    ans += mx * 1 / n;
  }
  cout << fixed << setprecision(12) << ans << endl;
}
