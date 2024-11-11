#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
bool endswith(string &s, int n, string t, int m) {
  if (n < m) return false;
  for (int i = n - m, j = 0; i < n; i++, j++)
    if (s[i] != t[j]) return false;
  return true;
}
int adjective(string &s) {
  int n = s.length();
  if (endswith(s, n, "lios", 4)) return 1;
  if (endswith(s, n, "liala", 5)) return 2;
  return 0;
}
int noun(string &s) {
  int n = s.length();
  if (endswith(s, n, "etr", 3)) return 1;
  if (endswith(s, n, "etra", 4)) return 2;
  return 0;
}
int verb(string &s) {
  int n = s.length();
  if (endswith(s, n, "initis", 6)) return 1;
  if (endswith(s, n, "inites", 6)) return 2;
  return 0;
}
int gg1[N], gg2[N], gg3[N];
int main() {
  int n = 0;
  string ss[N];
  while (cin >> ss[n]) n++;
  for (int i = 0; i < n; i++) gg1[i] = adjective(ss[i]);
  for (int i = 0; i < n; i++) gg2[i] = noun(ss[i]);
  for (int i = 0; i < n; i++) gg3[i] = verb(ss[i]);
  if (n == 1) {
    cout << (gg1[0] || gg2[0] || gg3[0] ? "YES" : "NO") << '\n';
    return 0;
  }
  int gender = gg1[0] ? gg1[0] : gg2[0] ? gg2[0] : gg3[0];
  int i = 1;
  while (i < n && gg1[i]) {
    if (gg1[i] != gender) {
      cout << "NO\n";
      return 0;
    }
    i++;
  }
  if (i == n || !gg2[i] || gg2[i] != gender) {
    cout << "NO\n";
    return 0;
  }
  i++;
  while (i < n && gg3[i]) {
    if (gg3[i] != gender) {
      cout << "NO\n";
      return 0;
    }
    i++;
  }
  cout << (i == n ? "YES" : "NO") << '\n';
  return 0;
}
