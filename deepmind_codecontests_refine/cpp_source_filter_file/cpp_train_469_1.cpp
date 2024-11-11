#include <bits/stdc++.h>
using namespace std;
long long n, x[100010], d = 1 << 17;
pair<long long, long long> tree[270000];
void update(long long i, pair<long long, long long> v) {
  tree[i] = v;
  while (i > 1) {
    i /= 2;
    tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
  }
}
pair<long long, long long> query(long long i, long long l, long long r,
                                 long long curl, long long curr) {
  if (l > r || curl > r || curr < l) return {1e9, 1e9};
  if (curl >= l && curr <= r) return tree[i];
  long long mid = (curl + curr) / 2;
  return min(query(i * 2, l, r, curl, mid),
             query(i * 2 + 1, l, r, mid + 1, curr));
}
int32_t main() {
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    cin >> x[i];
    x[i]--;
  }
  x[n - 1] = n - 1;
  for (auto &i : tree) i = {1e9, 1e9};
  update(d + n - 1, {n - 1, n - 1});
  long long sum = 0;
  for (long long i = n - 2; i >= 0; i--) {
    pair<long long, long long> j = query(1, i + 1, x[i], 0, d - 1);
    j.first += n - 1 - x[i];
    j.first -= i;
    sum += j.first;
    update(i + d, {j.first + i, i});
  }
  cout << sum << "\n";
  return 0;
}
