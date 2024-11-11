#include <bits/stdc++.h>
using namespace std;
long long X[5] = {0, -1, 0, 0, 1};
long long Y[5] = {0, 0, -1, 1, 0};
long long sol;
char e[100][100];
map<char, long long> mp;
int main() {
  long long n, m;
  cin >> n >> m;
  pair<int, int> S;
  for (int i = (int)0; i <= (int)n + 2; i++)
    for (int j = (int)0; j <= (int)m + 2; j++) e[j][i] = '#';
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)1; j <= (int)m; j++) {
      cin >> e[j][i];
      if (e[j][i] == 'S') S = pair<int, int>(j, i);
    }
  string s;
  cin >> s;
  for (int a = (int)1; a <= (int)4; a++)
    for (int b = (int)1; b <= (int)4; b++)
      for (int c = (int)1; c <= (int)4; c++)
        for (int d = (int)1; d <= (int)4; d++)
          if (a != b && a != c && a != d)
            if (b != c && b != d)
              if (c != d) {
                mp['0'] = a;
                mp['1'] = b;
                mp['2'] = c;
                mp['3'] = d;
                pair<int, int> pos = S;
                bool boo = false;
                for (int i = (int)0; i <= (int)s.size() - 1; i++) {
                  pos.first += X[mp[s[i]]];
                  pos.second += Y[mp[s[i]]];
                  if (e[pos.first][pos.second] == '#') {
                    boo = false;
                    goto lab;
                  }
                  if (e[pos.first][pos.second] == 'E') {
                    boo = true;
                    goto lab;
                  }
                }
              lab:
                sol += (boo == true);
              }
  cout << sol;
}
