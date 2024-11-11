#include <bits/stdc++.h>
using namespace std;
bool visi[27];
long long adj[27][2];
long long a[210];
long long out[80];
long long l = 39, r = 41;
string s;
long long fl;
int dfs(int c, long long p) {
  if (fl) return 0;
  if (p > 40) {
    if (adj[c][0] == out[p - 1]) {
      if (!visi[adj[c][1]]) {
        out[p + 1] = adj[c][1];
        p++;
        dfs(out[p], p);
      } else if (adj[c][1] != 0) {
        fl = 1;
      }
    }
    if (adj[c][1] == out[p - 1]) {
      if (!visi[adj[c][0]]) {
        out[p + 1] = adj[c][0];
        p++;
        dfs(out[p], p);
      } else if (adj[c][0] != 0) {
        fl = 1;
      }
    }
  }
  if (p < 40) {
    if (adj[c][0] == out[p + 1]) {
      if (!visi[adj[c][1]]) {
        out[p - 1] = adj[c][1];
        p--;
        dfs(out[p], p);
      } else if (adj[c][1] != 0) {
        fl = 1;
      }
    }
    if (adj[c][1] == out[p + 1]) {
      if (!visi[adj[c][0]]) {
        out[p - 1] = adj[c][0];
        p--;
        dfs(out[p], p);
      } else if (adj[c][0] != 0) {
        fl = 1;
      }
    }
  }
  visi[c] = true;
  return 0;
}
void solve() {
  for (long long i = 0; i < 27; i++) {
    visi[i] = false;
    adj[i][0] = 0, adj[i][1] = 0;
  }
  visi[0] = true;
  fl = 0;
  s.clear();
  for (long long i = 0; i < 80; i++) out[i] = 0;
  l = 39, r = 41;
  cin >> s;
  long long n = s.length();
  for (long long i = 0; i < s.length(); i++) {
    a[i] = s[i] - 'a' + 1;
  }
  for (long long i = 0; i < n; i++) {
    if (i == 0 && n >= 2 & a[0] != a[1]) {
      adj[a[i]][0] = a[1];
    } else if (i == n - 1 && n >= 2 && a[n - 1] != a[n - 2]) {
      if (adj[a[i]][0] == 0)
        adj[a[i]][0] = a[n - 2];
      else if (adj[a[i]][1] == 0 && adj[a[i]][0] != a[n - 2]) {
        adj[a[i]][1] = a[n - 2];
      } else if (adj[a[i]][1] != a[n - 2] && adj[a[i]][0] != a[n - 2]) {
        fl = 1;
        break;
      }
    } else {
      if (a[i] != a[i - 1]) {
        if (adj[a[i]][0] == 0)
          adj[a[i]][0] = a[i - 1];
        else if (adj[a[i]][1] == 0 && adj[a[i]][0] != a[i - 1]) {
          adj[a[i]][1] = a[i - 1];
        } else if (adj[a[i]][1] != a[i - 1] && adj[a[i]][0] != a[i - 1]) {
          fl = 1;
          break;
        }
      }
      if (a[i] != a[i + 1]) {
        if (adj[a[i]][0] == 0)
          adj[a[i]][0] = a[i + 1];
        else if (adj[a[i]][1] == 0 && adj[a[i]][0] != a[i + 1]) {
          adj[a[i]][1] = a[i + 1];
        } else if (adj[a[i]][1] != a[i + 1] && adj[a[i]][0] != a[i + 1]) {
          fl = 1;
          break;
        }
      }
    }
  }
  out[40] = a[0];
  if (adj[a[0]][0] != 0) {
    out[41] = adj[a[0]][0];
  }
  if (adj[a[0]][1] != 0) {
    out[39] = adj[a[0]][1];
  }
  visi[a[0]] = true;
  if (adj[a[0]][0] != 0) dfs(out[41], r);
  if (adj[a[0]][1] != 0 && !visi[adj[a[0]][1]])
    dfs(out[39], l);
  else if (adj[a[0]][1] != 0 && visi[adj[a[0]][1]]) {
    fl = 1;
  }
  if (fl)
    cout << "NO\n";
  else {
    cout << "YES\n";
    long long j = 0;
    while (j < 80 && out[j] == 0) {
      j++;
    }
    char w;
    while (j < 80 && out[j] != 0) {
      w = 'a' + out[j] - 1;
      cout << w;
      visi[out[j]] = true;
      j++;
    }
    for (long long e = 1; e < 27; e++) {
      w = 'a' + (e - 1);
      if (!visi[e]) cout << w;
    }
    cout << "\n";
  }
}
int main() {
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
