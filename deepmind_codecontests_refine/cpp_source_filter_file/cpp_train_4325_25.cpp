#include <bits/stdc++.h>
using namespace std;
string S;
vector<string> V;
int n, d[10005][3], ans;
void dp(int x, int len) {
  if (d[x][len] != 0) return;
  d[x][len] = 1;
  string s2(S, x - 1, 2), s3(S, x - 2, 3);
  if (len == 2) {
    if (x >= 6) {
      V.push_back(s2);
      dp(x - 2, 0);
    }
    if (x >= 7) {
      V.push_back(s3);
      dp(x - 3, 0);
    }
    return;
  }
  string st(S, x + 1, len + 2);
  if (x >= 6 && st != s2) {
    V.push_back(s2);
    dp(x - 2, 0);
  }
  if (x >= 7 && st != s3) {
    V.push_back(s3);
    dp(x - 3, 1);
  }
  return;
}
int main() {
  cin >> S;
  n = S.length();
  dp(n - 1, 2);
  sort(V.begin(), V.end());
  for (int i = 0; i < (int)V.size(); i++) {
    string t;
    if (i != 0) t = V[i - 1];
    if (V[i] != t) ans++;
  }
  cout << ans << endl;
  for (int i = 0; i < (int)V.size(); i++) {
    string t;
    if (i != 0) t = V[i - 1];
    if (V[i] != t) cout << V[i] << endl;
  }
}
