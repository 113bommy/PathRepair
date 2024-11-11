#include <bits/stdc++.h>
using namespace std;
const long long N = 228228;
char c;
map<int, int> o;
set<pair<long long, long long> >::iterator A;
pair<long long, long long> b;
set<pair<long long, long long> > a;
long long i, j, n, m, x, y;
int main() {
  cin >> n >> m;
  a.insert(make_pair(0, 1)), a.insert(make_pair(n + 1, 0));
  while (m--) {
    cin >> x >> y >> c;
    if (o[x]) {
      puts("0");
      continue;
    }
    if (c == 'U') {
      b = *a.lower_bound(make_pair(x, -1));
      if (b.second)
        o[x] = o[b.first] + (b.first - x);
      else
        o[x] = b.first - x;
      a.insert(make_pair(x, 1));
    } else {
      A = a.lower_bound(make_pair(x, -1)), A--, b = *A;
      if (b.second)
        o[x] = x - b.first;
      else
        o[i] = o[b.first] + (x - b.first);
      a.insert(make_pair(x, 0));
    }
    cout << o[x] << "\n";
  }
}
