#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const long long MOD = 1e9 + 7;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int _;
using namespace std;
char qqq[3][MAXN];
char aaa[3][MAXN];
char sss[MAXN];
int p[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  while (cin >> sss) {
    int len = strlen(sss);
    int base = 1;
    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j <= len - 1; ++j) qqq[i][j] = j / base % 26 + 'a';
      qqq[i][len] = 0;
      base *= 26;
    }
    for (int i = 0; i <= 2; ++i) {
      cout << "? " << qqq[i] << endl;
      cin >> aaa[i];
    }
    for (int i = 0; i <= len - 1; ++i) {
      int tmp = (aaa[0][i] - 'a') + (aaa[1][i] - 'a') * 26 +
                (aaa[2][i] - 'a') * 26 * 26;
      p[tmp] = i;
    }
    cout << "! ";
    for (int i = 0; i <= len - 1; ++i) cout << sss[p[i]];
    cout << endl;
  }
  return 0;
}
