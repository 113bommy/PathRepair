#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e5 + 7, M = 2e5 + 7;
int64_t IX = 1e18, IN = -1e18;
int64_t ten[] = {
    1,           10,           100,           1000,          10000,
    100000,      1000000,      10000000,      100000000,     1000000000,
    10000000000, 100000000000, 1000000000000, 10000000000000};
vector<int64_t> s_match, prime;
void scan(int64_t &a, int64_t &b = IX, int64_t &c = IX) {
  scanf("%lld", &a);
  if (b != IX) scan(b, c);
}
int64_t power(int64_t a, int64_t b, int64_t c) {
  if (b == 0)
    return 1;
  else if (b % 2 == 1)
    return (a * power(a, b - 1, c)) % c;
  int64_t value = power(a, b / 2, c) % c;
  return (value * value) % c;
}
void find_prime(int64_t n) {
  vector<bool> visited(n, 1);
  int64_t i, j;
  for (i = 2; i < n; i++) {
    if (visited[i]) {
      prime.push_back(i);
      for (j = 2 * i; j < n; j += i) visited[j] = 0;
    }
  }
}
int64_t inverse(int64_t a) {
  return power(a, 1000000007 - 2, 1000000007) % 1000000007;
}
int64_t gcd(int64_t a, int64_t b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool K_matcher(string p, string q) {
  int64_t i, k, num[N], flag = 0;
  num[0] = -1;
  k = -1;
  for (i = 1; i < p.size(); i++) {
    while (k > -1 && p[k + 1] != p[i]) k = num[k];
    if (p[k + 1] == p[i]) k++;
    num[i] = k;
  }
  k = -1;
  for (i = 0; i < q.size(); i++) {
    while (k > -1 && p[k + 1] != q[i]) k = num[k];
    if (p[k + 1] == q[i]) k++;
    if (k == p.size() - 1) {
      s_match.push_back(i - p.size() + 1);
      k = num[k];
      flag = 1;
    }
  }
  if (flag)
    return 1;
  else
    return 0;
}
int64_t X[] = {1, 0, -1, 0}, Y[] = {0, 1, 0, -1};
vector<int64_t> v[107];
vector<pair<int64_t, int64_t> > u;
bool visited[107];
bool dfs(int64_t a, int64_t b) {
  if (a == b) return 1;
  visited[a] = 1;
  int64_t i, j;
  bool flag = 0;
  for (i = 0; i < v[a].size(); i++) {
    j = v[a][i];
    if (!visited[j]) flag |= dfs(j, b);
  }
  return flag;
}
int main() {
  int64_t n, i, j, k, a, b, c, x, y, z, index = 0;
  scan(n);
  for (k = 0; k < n; k++) {
    scan(a);
    if (a == 1) {
      scan(a, b);
      for (i = 0; i < u.size(); i++) {
        x = u[i].first;
        y = u[i].second;
        if ((a < x && x < b) || (a < y && y < b)) {
          v[i].push_back(index);
        }
        if ((x < a && a < y) || (x < b && b < y)) {
          v[index].push_back(i);
        }
      }
      index++;
      u.push_back(make_pair(a, b));
    } else {
      memset(visited, 0, sizeof(visited));
      scan(a, b);
      a--;
      b--;
      if (dfs(a, b))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
