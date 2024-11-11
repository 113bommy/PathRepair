#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const int N = 100003;
int n;
long long int s[N][2];
vector<long long int> g[2];
long long int total = 1, men = 1, mai = 1, eq = 1, res = 0;
bool menor = false, maior = false, tem = false;
char c;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &c);
    if (c == '?')
      s[i][0] = -1;
    else
      s[i][0] = c - 48;
  }
  for (int i = 0; i < n; i++) {
    scanf(" %c", &c);
    if (c == '?')
      s[i][1] = -1;
    else
      s[i][1] = c - 48;
  }
  for (int i = 0; i < n; i++)
    if (s[i][0] != -1 && s[i][1] != -1) {
      if (s[i][0] > s[i][1])
        maior = true;
      else if (s[i][0] < s[i][1])
        menor = true;
    } else {
      g[0].push_back(s[i][0]);
      g[1].push_back(s[i][1]);
    }
  for (int i = 0; i < g[0].size(); i++) {
    if (g[0][i] == -1 && g[1][i] == -1) total = (total * 10) % mod;
    if (g[0][i] == -1 || g[1][i] == -1) total = (total * 10) % mod;
  }
  if (!maior) {
    for (int i = 0; i < g[0].size(); i++)
      if (g[0][i] == -1 && g[1][i] == -1) {
        men = (men * 55) % mod;
      } else if (g[0][i] == -1) {
        men = (men * (g[1][i] + 1)) % mod;
      } else {
        men = (men * (10 - g[0][i])) % mod;
      }
    res = res + men + mod;
  }
  if (!menor) {
    for (int i = 0; i < g[0].size(); i++)
      if (g[0][i] == -1 && g[1][i] == -1) {
        mai = (mai * 55) % mod;
      } else if (g[0][i] == -1) {
        mai = (mai * (10 - g[1][i])) % mod;
      } else {
        mai = (mai * (g[0][i] + 1)) % mod;
      }
    res = res + mai + mod;
  }
  if (!maior && !menor) {
    for (int i = 0; i < g[0].size(); i++)
      if (g[0][i] == -1 && g[1][i] == -1) eq = (eq * 10) % mod;
    res = res - eq;
  }
  if (total == 1 && !(maior && menor)) res = 1;
  printf("%lld\n", total - (res) % mod + mod);
  return 0;
}
