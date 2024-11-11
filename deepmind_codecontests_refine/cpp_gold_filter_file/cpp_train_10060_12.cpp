#include <bits/stdc++.h>
using namespace std;
void fileio() {}
vector<vector<long long int>> g;
vector<long long int> bit;
long long int n;
void add(long long int i, long long int x) {
  while (i <= n) {
    bit[i] += x;
    i += (i & (-i));
  }
}
long long int query(long long int i) {
  long long int sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= (i & (-i));
  }
  return sum;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fileio();
  cin >> n;
  bit = vector<long long int>(n + 1, 0);
  vector<long long int> p(n, 0), candi(n + 1, 0), contri(n + 1, 0);
  set<long long int> s;
  for (long long int i = 0; i < n; i++) {
    cin >> p[i];
    long long int more = query(n) - query(p[i]);
    add(p[i], 1);
    if (more == 1) {
      long long int x = (*s.rbegin());
      candi[x]++;
    }
    if (more == 0) {
      contri[p[i]]++;
    }
    s.insert(p[i]);
  }
  long long int res = 1;
  for (long long int i = 1; i <= n; i++)
    if (candi[i] - contri[i] > candi[res] - contri[res]) res = i;
  cout << res;
  return 0;
}
