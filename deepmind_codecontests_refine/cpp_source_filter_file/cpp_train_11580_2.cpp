#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
int query(const string &s) {
  assert(!s.empty() && s.length() <= 300);
  cout << s << endl;
  int dist;
  cin >> dist;
  assert(dist != -1);
  if (dist == 0) exit(0);
  return dist;
}
int main() {
  string a_str = "", b_str = "";
  for (int _ = (0); _ < (300); ++_) a_str += 'a';
  for (int _ = (0); _ < (300); ++_) b_str += 'b';
  int a = 300 - query(a_str), b = 300 - query(b_str);
  string spell = "";
  for (int _ = (0); _ < (a); ++_) spell += 'a';
  int dist = b;
  for (int i = (0); i < (spell.length()); ++i) {
    if ((i - 1 < 0 || spell[i - 1] == 'a') && spell[i] == 'a') {
      while (b > 0) {
        string cp = spell;
        cp.insert(cp.begin() + i, 'b');
        int now = query(cp);
        if (now == dist) break;
        --dist;
        --b;
        spell.insert(spell.begin() + i, 'b');
      }
    }
  }
  while (b--) spell += 'b';
  query(spell);
  assert(false);
}
