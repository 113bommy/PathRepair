#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int n;
  vector<int> xs;
  BIT(int n) : n(n) { xs.resize(n + 1); }
  void add(int i, int v) {
    for (int x = i + 1; x <= n; x += x & -x) xs[x] += v;
  }
  int sum(int i) {
    int s = 0;
    for (int x = i + 1; x > 0; x -= x & -x) s += xs[x];
    return s;
  }
  int sum(int a, int b) { return sum(b) - sum(a - 1); }
};
int N;
int A[100000];
vector<int> G[100000];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vector<int> xs;
  for (int i = 0; i < (N); i++) {
    cin >> A[i];
    xs.push_back(A[i]);
  }
  sort((xs).begin(), (xs).end());
  xs.erase(unique((xs).begin(), (xs).end()), (xs).end());
  for (int i = 0; i < (N); i++) {
    A[i] = lower_bound((xs).begin(), (xs).end(), A[i]) - xs.begin();
    G[A[i]].push_back(i);
  }
  BIT bit(N);
  for (int i = 0; i < (N); i++) bit.add(i, 1);
  int pos = 0;
  long long sum = 0;
  for (int h = 0; h < (xs.size()); h++) {
    assert(!G[h].empty());
    int head = 0;
    if (pos <= G[h].back())
      head = lower_bound((G[h]).begin(), (G[h]).end(), pos) - G[h].begin();
    for (int i = 0; i < (G[h].size()); i++) {
      int o = (head + i) % ((int)G[h].size());
      int next = G[h][o];
      if (pos <= next)
        sum += bit.sum(pos, next);
      else {
        sum += bit.sum(pos, N - 1);
        sum += bit.sum(next);
      }
      pos = next;
      bit.add(pos, -1);
    }
  }
  cout << sum << "\n";
  return 0;
}
