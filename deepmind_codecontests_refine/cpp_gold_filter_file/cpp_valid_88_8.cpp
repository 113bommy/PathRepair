#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int maxn = 3e2 + 10;
const int maxm = maxn * maxn;
vector<int> arr;
int find(int first) {
  return lower_bound(arr.begin(), arr.end(), first) - arr.begin() + 1;
}
int c[maxn][maxm], num[maxm];
pair<int, int> b[maxm];
void add(int first, int second, int z) {
  while (first < maxm) {
    c[second][first] += z;
    first += first & -first;
  }
}
int ask(int first, int second) {
  int sum = 0;
  while (first) {
    sum += c[second][first];
    first -= first & -first;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  int __;
  cin >> __;
  while (__--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) {
      int num;
      cin >> num;
      b[i].first = num;
      b[i].second = i;
      arr.push_back(num);
    }
    sort(b + 1, b + n * m + 1);
    for (int i = 1; i <= n * m; ++i) num[b[i].second] = (i - 1) / m + 1;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    long long sum = 0;
    for (int i = 1; i <= n * m; ++i) swap(b[i].first, b[i].second);
    sort(b + 1, b + n * m + 1);
    for (int i = 1; i <= n * m; ++i) swap(b[i].first, b[i].second);
    for (int i = 1; i <= n * m; ++i) {
      b[i].first = find(b[i].first);
      sum += ask(b[i].first - 1, num[b[i].second]);
      add(b[i].first, num[b[i].second], 1);
    }
    cout << sum << '\n';
    for (int i = 1; i <= n * m; ++i) add(b[i].first, num[b[i].second], -1);
    arr.clear();
  }
  return 0;
}
