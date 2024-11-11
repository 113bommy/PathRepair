#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s, p, q;
  map<int, int> bm, sm;
  char a;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a >> p >> q;
    if (a == 'B') {
      bm[p] += q;
    } else {
      sm[p] += q;
    }
  }
  int c = 0;
  int z = sm.size();
  int k = z - s;
  for (map<int, int>::reverse_iterator it = sm.rbegin(); it != sm.rend();
       it++) {
    if (k <= 0) cout << "S " << it->first << ' ' << it->second << '\n';
    k--;
  }
  c = 0;
  for (map<int, int>::reverse_iterator it = bm.rbegin();
       it != bm.rend() && c < s; it++, c++) {
    cout << "B " << it->first << ' ' << it->second << '\n';
  }
}
