#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, m, k, out_siz[siz], a[siz];
string to_print[siz];
priority_queue<pair<long long, long long> > q;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long op;
    cin >> op;
    a[i] = op;
    if (!op) {
      long long done = 0;
      while (done < 3 and q.size()) {
        out_siz[i] = done + 1;
        string cur;
        if (done == 0)
          cur = "pushStack";
        else if (done == 1)
          cur = "pushQueue";
        else
          cur = "pushFront";
        to_print[q.top().second] = cur;
        done++;
        q.pop();
      }
      while (q.size()) q.pop();
    } else
      q.push({a[i], i});
  }
  for (long long i = 1; i <= n; i++) {
    if (!a[i]) {
      cout << out_siz[i];
      if (out_siz[i] == 1) {
        cout << " popStack\n";
      } else if (out_siz[i] == 2) {
        cout << " popStack popQueue\n";
      } else if (out_siz[i] == 3)
        cout << " popStack popQueue popFront\n";
      else
        cout << endl;
    } else {
      if (to_print[i] != "")
        cout << to_print[i] << endl;
      else
        cout << "pushBack\n";
    }
  }
}
