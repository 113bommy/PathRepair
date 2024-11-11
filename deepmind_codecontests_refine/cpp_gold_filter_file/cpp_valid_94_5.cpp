#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int x = power(a, n / 2);
  if (n % 2 != 0)
    return a * x * x;
  else
    return x * x;
}
long long int power(long long int a, long long int n, long long int m) {
  if (n == 0) return 1;
  long long int x = power(a, n / 2, m);
  if (n % 2 != 0)
    return (((a * x) % m) * (x) % m) % m;
  else
    return (x * x) % m;
}
class DisjointSet {
 public:
  vector<int> parent;
  DisjointSet(int n) : parent(n) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  void join(int a, int b) { parent[find(b)] = find(a); }
  int find(int a) { return a == parent[a] ? a : parent[a] = find(parent[a]); }
  bool check(int a, int b) { return find(a) == find(b); }
};
long long int solve(long long int x, vector<long long int> v1) {
  cout << x << " ";
  string s = to_string(x);
  reverse(s.begin(), s.end());
  long long int c = 0;
  long long int ans = 1;
  for (int i = 0; i < s.size(); i++) {
    if (!v1[i]) {
      long long int a = (s[i] - '0') - c;
      c = 0;
      ans = (ans * (a + 1));
    } else {
      long long int a = (s[i] - '0') - c;
      a = 9 - a;
      c = 1;
      ans = (ans * (a));
    }
  }
  cout << ans << " ";
  return ans;
}
long long int fun(long long int i, string &s, vector<long long int> &v,
                  long long int n) {
  long long int x = 0;
  if (i == n) {
    return 1;
  }
  long long int c = 0;
  if (i - 2 >= 0 && v[i - 2] == 1) {
    c = 1;
  }
  if (c <= (s[i] - '0')) x = ((s[i] - '0') - c + 1) * fun(i + 1, s, v, n);
  if (i + 2 < n) {
    v[i] = 1;
    if (c == 1 && s[i] == '0') {
      x += (10) * fun(i + 1, s, v, n);
    } else
      x += (9 + c - ((s[i] - '0'))) * fun(i + 1, s, v, n);
  }
  v[i] = 0;
  return x;
}
int32_t main() {
  long long int i, n, j, x, y, m, k, t, sum, count, cnt, b, c, d, j1, z, a, o,
      temp;
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  vector<long long int> v;
  v.push_back(90);
  for (int i = 1; i < 10; i++) {
    v.push_back(v[i - 1] * 10);
  }
  while (t--) {
    string s;
    cin >> s;
    n = s.size();
    reverse(s.begin(), s.end());
    vector<long long int> v1(n, 0);
    cout << fun(0, s, v1, n) - 2 << "\n";
  }
  return 0;
}
