#include <bits/stdc++.h>
using namespace std;
long long fen[200009] = {0};
const long long M = 200005;
void update(long long ind, long long b, long long *fen) {
  long long i = ind;
  while (i <= M - 2 && i > 0) {
    fen[i] += b;
    i = i + (i & (-i));
  }
}
long long sum(long long ind, long long *fen) {
  long long sum = 0;
  long long i = ind;
  while (i > 0) {
    sum += fen[i];
    i = i - (i & (-i));
  }
  return sum;
}
long long ele(long long pos, long long *fen) {
  long long l = 1;
  long long r = M - 1;
  while (l != r) {
    long long m = (l + r) / 2;
    if (sum(m, fen) >= pos) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}
int32_t main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n + 1];
  map<long long, vector<long long>> mp;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = n; i >= 1; i--) {
    mp[a[i]].push_back(i);
  }
  set<pair<pair<long long, long long>, long long>> s;
  long long m;
  cin >> m;
  long long final[m + 1];
  for (long long i = 1; i <= m; i++) {
    long long aa, b;
    cin >> aa >> b;
    s.insert({{aa, b}, i});
  }
  s.insert({{(long long)(1e17), (long long)(1e17)}, (long long)(1e17)});
  auto it = mp.end();
  it--;
  auto pt = s.begin();
  for (long long i = 1; i <= n; i++) {
    if ((long long)(it->second.size()) == 0) {
      it--;
    }
    long long psh = (it->second).back();
    (it->second).pop_back();
    update(psh, 1, fen);
    while (pt->first.first == i) {
      long long ind = pt->second;
      long long pos = pt->first.second;
      final[ind] = a[ele(pos, fen)];
      pt++;
    }
  }
  for (long long i = 1; i <= m; i++) {
    cout << final[i] << endl;
  }
}
