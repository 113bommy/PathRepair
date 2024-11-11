#include <bits/stdc++.h>
using namespace std;
long long int x8[] = {1, 1, 1, 0, 0, -1, -1, -1};
long long int y8[] = {1, 0, -1, 1, -1, -1, 0, -1};
long long int x4[] = {1, -1, 0, 0};
long long int y4[] = {0, 0, 1, -1};
long long int mod = 1e9 + 7;
long long int inf = 1e17;
const int MAXN = 100000;
long long int bit[MAXN][27];
void update(int pos, int c, int val) {
  while (pos <= MAXN) {
    bit[pos][c] += val;
    pos += (pos & -pos);
  }
}
int query(int pos, int c) {
  int ans = 0;
  while (pos > 0) {
    ans += bit[pos][c];
    pos -= (pos & -pos);
  }
  return ans;
}
void getac() {
  string s;
  cin >> s;
  int n = s.length();
  s = " " + s;
  int q;
  cin >> q;
  int type;
  char c;
  int ind;
  int l, r;
  for (int i = 1; i <= n; i++) {
    update(i, s[i] - 'a', 1);
  }
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> ind >> c;
      update(ind, s[ind] - 'a', -1);
      update(ind, c - 'a', 1);
      s[ind] = c;
    } else {
      int ans = 0;
      cin >> l >> r;
      for (int i = 0; i < 26; i++) {
        int lans = query(r, i);
        int rans = query(l - 1, i);
        if (lans != rans) {
          ans++;
        }
      }
      cout << ans << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  ;
  long long int t;
  t = 1;
  while (t--) {
    getac();
  }
  return 0;
}
