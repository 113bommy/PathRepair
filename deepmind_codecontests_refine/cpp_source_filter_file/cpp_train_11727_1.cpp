#include <bits/stdc++.h>
#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
const int N = 1100;
const int MAXN = int(1e6) + 100;
const int Mmask = (1 << 20);
const int mod = int(1e9) + 7;
const long long MOD = (long long)(1e18) + 7ll;
int solution();
int main(int argc, char* const argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return solution();
}
string s, t;
int p[MAXN], p1[MAXN], su[MAXN], su1[MAXN];
int solution() {
  cin >> s >> t;
  s = '$' + s;
  t = '$' + t;
  for (int i = 1; i < s.size(); i++)
    p[i] = p[i - 1] + (s[i] == 'B' || s[i] == 'C');
  for (int i = 1; i < t.size(); i++)
    p1[i] = p1[i - 1] + (t[i] == 'B' || t[i] == 'C');
  for (int i = 1; i < s.size(); i++) su[i] = (s[i] == 'A' ? su[i - 1] + 1 : 0);
  for (int i = 1; i < t.size(); i++)
    su1[i] = (t[i] == 'A' ? su1[i - 1] + 1 : 0);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int prefs = p[b] - p[a - 1], preft = p1[d] - p1[c - 1];
    int suffs = min(su[b], b - a + 1), sufft = min(su1[d], d - c + 1);
    if (!prefs && preft && suffs == sufft)
      cout << 1;
    else {
      if ((prefs % 2) == (preft % 2) && preft <= prefs && suffs >= sufft) {
        int d = (suffs - sufft) % 3;
        if (d == 0)
          cout << 1;
        else {
          if (prefs + 2 <= preft)
            cout << 1;
          else
            cout << 0;
        }
      } else
        cout << 0;
    }
  }
  return 0;
}
