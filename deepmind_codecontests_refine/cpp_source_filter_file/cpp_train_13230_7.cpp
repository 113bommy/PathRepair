#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long MAX = 1e5 + 5;
long long ava[65];
long long rava[65];
bool iso[MAX][6];
bool inv[MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(25);
  long long a, b, c, d, i, j, k, l;
  long long e, f, m;
  string s;
  cin >> s;
  string p;
  l = s.size();
  cin >> m;
  while (m--) {
    cin >> a;
    a--;
    inv[a] = true;
    cin >> p;
    c = 0;
    for (i = 0; i < p.length(); i++) {
      b = (long long)(p[i] - 'a');
      iso[a][b] = true;
      c += 1 << b;
    }
    for (i = 1; i < 64; i++) {
      if ((i & c) > 0) ava[i]++;
    }
  }
  for (i = 0; i < l; i++) {
    if (!inv[i]) {
      for (j = 1; j < 64; j++) ava[j]++;
      for (j = 0; j < 6; j++) iso[i][j] = true;
    }
    b = (long long)(s[i] - 'a');
    for (j = 1; j < 64; j++) {
      if ((j & (1 << b)) > 0) rava[j]++;
    }
  }
  for (i = 1; i < 64; i++) {
    if (rava[i] > ava[i]) {
      cout << "Impossible\n";
      break;
    }
  }
  char ans[l];
  for (i = 0; i < l; i++) {
    c = 0;
    for (j = 0; j < 6; j++)
      if (iso[i][j]) c += 1 << j;
    for (j = 0; j < 6; j++) {
      if (!iso[i][j]) continue;
      bool fl = false;
      for (k = 0; k < 64; k++) {
        if ((k & (1 << j)) > 0) rava[k]--;
        if (k & c) ava[k]--;
        if (rava[k] > ava[k]) fl = true;
      }
      if (!fl) break;
      for (k = 0; k < 64; k++) {
        if ((k & (1 << j)) > 0) rava[k]++;
        if (k & c) ava[k]++;
      }
    }
    ans[i] = (char)('a' + j);
  }
  for (i = 0; i < l; i++) {
    cout << ans[i];
  }
  return 0;
}
