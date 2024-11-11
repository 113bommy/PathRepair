#include <bits/stdc++.h>
using namespace std;
long long re, cur, n, check, pos, Free[50];
double cnt, tmp;
string s;
vector<long long> d[100];
int main() {
  cin >> s;
  n = s.length();
  s = s + s;
  for (int i = 0; i < n; i++) {
    d[int(s[i] - 'a')].push_back(i);
  }
  for (int x = 0; x < 26; x++) {
    re = 0;
    for (int k = 1; k <= n - 1; k++) {
      cur = 0;
      memset(Free, 0, sizeof(Free));
      for (int i = 0; i < d[x].size(); i++) {
        pos = d[x][i];
        Free[int(s[pos + k] - 'a')]++;
      }
      for (int i = 0; i < 26; i++)
        if (Free[i] == 1) cur++;
      re = max(re, cur);
    }
    cnt = cnt + re;
  }
  tmp = n;
  printf("%.15f", (cnt / tmp));
}
