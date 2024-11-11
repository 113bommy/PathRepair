#include <bits/stdc++.h>
using namespace std;
int long long mod = 1e9 + 7;
int long long mod1 = -1 * mod;
vector<int long long> v[1000001];
int long long level[1000001] = {0};
int long long in[1000001] = {0};
int long long out[1000001] = {0};
int long long low[1000001] = {0};
int long long vis[1000001] = {0};
int long long visit[1001][1001] = {0};
int long long dis[1001][1001] = {0};
int long long dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int long long dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int long long timer = 0, n, m, t, k, eq = 0;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) {
    string s, p;
    cin >> s;
    p = s;
    n = s.size();
    string a[4] = {"00", "25", "75", "50"};
    int long long ans = 0;
    if (n == 1 && (s[0] == '0' || s[0] == '_' || s[0] == 'X'))
      cout << 1 << "\n";
    else if (n >= 2) {
      for (int long long i = 0; i < 4; i++) {
        s = p;
        if (s[n - 1] == '_') {
          s[n - 1] = a[i][1];
          if (s[n - 2] == '_')
            s[n - 2] = a[i][0];
          else if (s[n - 2] == 'X') {
            for (int long long j = 0; j < n; j++) {
              if (s[j] == 'X') {
                s[j] = a[i][0];
              }
            }
          }
          if (s[n - 1] == a[i][1] && s[n - 2] == a[i][0])
            if (s[0] != '0') {
              int long long temp = 1;
              if (s[0] == '_')
                temp = 9, s[0] = 1;
              else if (s[0] == 'X') {
                temp = 9;
                for (int long long j = 0; j < n; j++) {
                  if (s[j] == 'X') {
                    s[j] = '1';
                  }
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == '_') {
                  temp *= 10;
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == 'X') {
                  temp *= 10;
                  break;
                }
              }
              ans += temp;
            }
        } else if (s[n - 1] == 'X') {
          s[n - 1] == a[i][1];
          for (int long long j = 0; j < n; j++) {
            if (s[j] == 'X') {
              s[j] = a[i][1];
            }
          }
          if (s[n - 2] == '_') {
            s[n - 2] = a[i][0];
          }
          if (s[n - 1] == a[i][1] && s[n - 2] == a[i][0])
            if (s[0] != '0') {
              int long long temp = 1;
              if (s[0] == '_')
                temp = 9, s[0] = 1;
              else if (s[0] == 'X') {
                temp = 9;
                for (int long long j = 0; j < n; j++) {
                  if (s[j] == 'X') {
                    s[j] = '1';
                  }
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == '_') {
                  temp *= 10;
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == 'X') {
                  temp *= 10;
                  break;
                }
              }
              ans += temp;
            }
        } else if (s[n - 2] == '_' || s[n - 2] == 'X') {
          if (s[n - 2] == '_')
            s[n - 2] = a[i][0];
          else if (s[n - 2] == 'X') {
            for (int long long j = 0; j < n; j++) {
              if (s[j] == 'X') {
                s[j] = a[i][0];
              }
            }
          }
          if (s[n - 1] == a[i][1] && s[n - 2] == a[i][0])
            if (s[0] != '0') {
              int long long temp = 1;
              if (s[0] == '_')
                temp = 9, s[0] = 1;
              else if (s[0] == 'X') {
                temp = 9;
                for (int long long j = 0; j < n; j++) {
                  if (s[j] == 'X') {
                    s[j] = '1';
                  }
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == '_') {
                  temp *= 10;
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == 'X') {
                  temp *= 10;
                  break;
                }
              }
              ans += temp;
            }
        } else {
          if (s[n - 1] == a[i][1] && s[n - 2] == a[i][0])
            if (s[0] != '0') {
              int long long temp = 1;
              if (s[0] == '_')
                temp = 9, s[0] = 1;
              else if (s[0] == 'X') {
                temp = 9;
                for (int long long j = 0; j < n; j++) {
                  if (s[j] == 'X') {
                    s[j] = '1';
                  }
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == '_') {
                  temp *= 10;
                }
              }
              for (int long long j = 1; j <= n - 1; j++) {
                if (s[j] == 'X') {
                  temp *= 10;
                  break;
                }
              }
              ans += temp;
            }
        }
      }
      cout << ans << "\n";
    } else
      cout << 0 << "\n";
  }
}
