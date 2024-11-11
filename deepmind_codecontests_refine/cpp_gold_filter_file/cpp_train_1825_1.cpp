#include <bits/stdc++.h>
using namespace std;
ifstream fin(".in");
int x, y;
int i, j, n, m, a, b, k, unu, zero, q, pos, val, start, finish, c, pi[200010];
long long int ans;
char ans2[100010];
int l, r, t;
bool ok, ok2;
pair<long long int, char> N[200010], M[200010];
clock_t t1, t2;
queue<int> Q;
map<int, int> mip;
string s;
long long int getNum() {
  int i = 0;
  long long int ans = 0;
  while (true) {
    if (s[i] >= '0' && s[i] <= '9')
      ans = ans * 10 + s[i] - '0';
    else
      return ans;
    i++;
  }
}
int main() {
  cin >> n >> m;
  swap(n, m);
  for (i = 1; i <= m; i++) {
    cin >> s;
    if (i == 0 || s[s.size() - 1] != M[i - 1].second)
      M[i] = {getNum(), s[s.size() - 1]};
    else {
      M[i - 1].first += getNum();
      i--;
      m--;
    }
  }
  for (i = 0; i < n; i++) {
    cin >> s;
    if (i == 0 || s[s.size() - 1] != N[i - 1].second)
      N[i] = {getNum(), s[s.size() - 1]};
    else {
      N[i - 1].first += getNum();
      i--;
      n--;
    }
  }
  if (n <= 2) {
    if (n == 1) {
      for (i = 1; i <= m; i++)
        if (N[0].second == M[i].second && N[0].first <= M[i].first) {
          ans += M[i].first - N[0].first + 1;
        }
    } else {
      for (i = 1; i < m; i++) {
        if (N[0].second == M[i].second && N[1].second == M[i + 1].second &&
            N[0].first <= M[i].first && N[1].first <= M[i + 1].first)
          ++ans;
      }
    }
    cout << ans;
    return 0;
  }
  n--;
  for (i = 2; i <= n; i++) {
    while (k > 0 && N[k + 1] != N[i]) k = pi[k];
    if (N[k + 1] == N[i]) k++;
    pi[i] = k;
  }
  for (i = 1; i <= m; i++) {
    while (q > 0 && N[q + 1] != M[i]) q = pi[q];
    if (N[q + 1] == M[i]) q++;
    if (q == n - 1) {
      if (N[0].second == M[i - n + 1].second &&
          N[0].first <= M[i - n + 1].first)
        if (N[n].second == M[i + 1].second && N[n].first <= M[i + 1].first)
          ++ans;
    }
  }
  cout << ans;
  return 0;
}
