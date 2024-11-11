#include <bits/stdc++.h>
using namespace std;
int c[26][26];
bool found[100][26][100];
int state[100][26][100];
string s;
int ctoi(char c) { return int(c - 'a'); }
int find(int cur, int last, int liko) {
  if (liko == -1) return -1000000000;
  if (cur == s.size()) return 0;
  if (found[cur][last][liko]) return state[cur][last][liko];
  int best = -1;
  for (int i = 0; i < 26; i++)
    best = max(best, c[last][i] +
                         find(cur + 1, i, ctoi(s[cur]) == i ? liko : liko - 1));
  found[cur][last][liko] = true;
  state[cur][last][liko] = best;
  return state[cur][last][liko];
}
int main(void) {
  int k, n;
  cin >> s >> k >> n;
  if (s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; i++) {
    char x, y;
    cin >> x >> y;
    cin >> c[ctoi(x)][ctoi(y)];
  }
  int ans = -1000000000;
  for (int i = 0; i < 26; i++)
    ans = max(ans, find(1, i, ctoi(s[0]) == i ? k : k - 1));
  cout << ans << endl;
}
