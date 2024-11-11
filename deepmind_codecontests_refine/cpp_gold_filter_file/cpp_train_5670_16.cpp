#include <bits/stdc++.h>
using namespace std;
long L, l[1 << 20], ps[1 << 20], active[1 << 20], b, f, tests, ans[1 << 20];
long tp;
set<long> nice;
set<long>::iterator it;
long cur;
long id;
void check(long x) {
  if (x + l[cur] > L) return;
  for (int i = 1; i < cur; i++)
    if (active[i] > 0 && ps[i] > x - b && ps[i] < x + f + l[cur]) return;
  nice.insert(x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> L >> b >> f;
  cin >> tests;
  for (int i = 1; i <= tests; i++) ans[i] = -1;
  for (int i = 1; i <= tests; i++) {
    cin >> tp;
    cur = i;
    if (tp == 1) {
      cin >> l[i];
      nice.clear();
      check(0);
      for (int j = 1; j < i; j++) {
        if (active[j] == 1) {
          check(l[j] + ps[j] + b);
        }
      }
      if (nice.size() == 0) {
        cout << -1 << endl;
        continue;
      }
      active[i] = 1;
      it = nice.begin();
      ps[i] = (*it);
      ans[i] = (*it);
      cout << (*it) << endl;
    } else {
      cin >> id;
      active[id] = 0;
      continue;
    }
  }
  cin.get();
  cin.get();
  return 0;
}
