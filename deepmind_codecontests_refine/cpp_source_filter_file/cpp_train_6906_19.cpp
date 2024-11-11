#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const long long INF64 = 1e18;
const long double EPS = 1e-7;
mt19937 myrand(time(NULL));
const int N = 200 * 1000 + 13;
string s[N];
bool used[N];
int n;
bool read() {
  n = 0;
  memset(used, 0, sizeof(used));
  while (getline(cin, s[n])) {
    int pos = 0;
    while (pos < (int)(s[n]).size() && s[n][pos] == ' ') pos++;
    if (pos < (int)(s[n]).size() && s[n][pos] == '#') used[n] = 1;
    s[n] += '\n';
    n++;
  }
  return 1;
}
void fixSpaces(int k) {
  string t = "";
  for (int i = 0; i < ((int)(s[k]).size()); i++)
    if (s[k][i] != ' ') t += s[k][i];
  s[k] = t;
}
void fixNL(int k) { s[k] = s[k].substr(0, (int)(s[k]).size() - 1); }
void solve() {
  for (int i = 0; i < (n); i++) {
    if (!used[i]) fixSpaces(i);
    if (!used[i] && (i == n - 1 || !used[i + 1])) fixNL(i);
    printf("%s", s[i].c_str());
  }
}
int main() {
  if (read()) solve();
  return 0;
}
