#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
long long int power(long long int x, long long int n, long long int m) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return (power(((x % m) * (x % m)) % m, n / 2, m)) % m;
  else
    return ((x % m) * power(x, n - 1, m) % m);
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long int ncr(int n, int r) {
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  long long int ans = 1;
  int i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long int n, m, a;
  cin >> n;
  long long int num[n];
  map<long long int, long long int> fin;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    fin[num[i]]++;
  }
  cin >> m;
  vector<pair<long long int, long long int>> vec(m, {0, 0});
  for (int i = 0; i < m; i++) {
    cin >> a;
    vec[i].first = a;
  }
  for (int i = 0; i < m; i++) {
    cin >> a;
    vec[i].second = a;
  }
  long long int ans = 0, d = 0, e = 0;
  for (int i = 0; i < vec.size(); i++) {
    long long int a = vec[i].first;
    long long int b = vec[i].second;
    long long int p = fin[a];
    long long int q = fin[b];
    if (p > d) {
      d = p, e = q, ans = i + 1;
    }
    if (p == d) {
      if (q > e) ans = i + 1, d = p, e = q;
    }
  }
  cout << ans;
  return 0;
}
