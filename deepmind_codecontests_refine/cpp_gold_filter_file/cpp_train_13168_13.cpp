#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, S;
  scanf("%d", &n);
  scanf("%d", &S);
  string st;
  map<int, int> b, s;
  for (int i = 0; i < n; i++) {
    cin >> st;
    int p, q;
    scanf("%d", &p);
    scanf("%d", &q);
    if (st[0] == 'B') {
      b[p] += q;
    } else {
      s[p] += q;
    }
  }
  int ct = max(0, (int)s.size() - S);
  for (map<int, int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
    if (ct) {
      ct--;
      continue;
    }
    cout << "S " << it->first << " " << it->second << endl;
  }
  ct = 0;
  for (map<int, int>::reverse_iterator it = b.rbegin(); it != b.rend(); it++) {
    cout << "B " << it->first << " " << it->second << endl;
    ct++;
    if (ct == S) break;
  }
  return 0;
}
