#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;
const int maxn = 100100;
long long bit[maxn];
void update(int ix, long long v) {
  while (ix < maxn) {
    bit[ix] += v;
    ix += ix & ix;
  }
}
long long sum(int ix) {
  long long answer = 0;
  while (ix) {
    answer += bit[ix];
    ix -= ix & -ix;
  }
  return answer;
}
long long gcd(long long a, long long b) {
  while (b) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<long long, long long>>> dirs(n);
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    vector<pair<long long, long long>> a(m + 1);
    for (int j = 0; j < m; ++j) {
      cin >> a[j].first >> a[j].second;
    }
    a[m] = a[0];
    for (int j = 0; j < m; ++j) {
      long long x = a[j + 1].first - a[j].first;
      long long y = a[j + 1].second - a[j].second;
      long long g = gcd(abs(x), abs(y));
      x /= g;
      y /= g;
      dirs[i].push_back(pair<long long, long long>(x, y));
    }
  }
  int q;
  cin >> q;
  vector<pair<long long, long long>> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i].first >> queries[i].second;
  }
  vector<int> order(q);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(),
       [&](int u, int v) { return queries[u].second < queries[v].second; });
  vector<long long> answer(q, -1);
  map<pair<long long, long long>, int> last;
  for (int i = 1, j = 0; i <= n; ++i) {
    for (auto d : dirs[i - 1]) {
      if (last.find(d) != last.end()) update(last[d], -1);
      update(i, +1);
      last[d] = i;
    }
    for (; j < q && queries[order[j]].second == i; ++j) {
      int u = order[j];
      int a = queries[u].first, b = queries[u].second;
      answer[u] = last.size() - sum(a - 1);
    }
  }
  for (int i = 0; i < q; ++i) {
    assert(answer[i] != -1);
    cout << answer[i] << '\n';
  }
  return 0;
}
