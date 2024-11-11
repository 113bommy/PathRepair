#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
long long int advceil(long long int num, long long int den) {
  return (num % den == 0 ? num / den : num / den + 1);
}
long long int lstbt(long long int val) {
  long long int msk = val & (val - 1);
  return log2(val ^ msk);
}
long long int modmul(long long int a, long long int b) {
  if (a < 1e9 and b < 1e9) return (a * b) % 1000000007;
  a %= 1000000007;
  b %= 1000000007;
  long long int res = 0;
  while (b > 0) {
    if (b & 1) res = (res + a) % 1000000007;
    a = (a * 2) % 1000000007;
    b /= 2;
  }
  return res;
}
long long int modexpo(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = modmul(res, a);
    a = modmul(a, a);
    b /= 2;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return a == 0 ? b : gcd(b % a, a);
}
vector<long long int> CALCfactor(long long int n) {
  vector<long long int> factor(n + 2, 0);
  for (long long int i = 4; i <= n; i += 2) factor[i] = 2;
  for (long long int j = 3; j <= n; j += 2) {
    if (factor[j]) continue;
    for (long long int i = 2 * j; i <= n; i += j) factor[i] = j;
  }
  return factor;
}
vector<long long int> CALCprimeNUM(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> primeNUM;
  primeNUM.reserve(n + 2);
  for (long long int i = 2; i <= n; i++)
    if (!factor[i]) primeNUM.push_back(i);
  return primeNUM;
}
vector<long long int> CALCprimeFACTOR(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> ans;
  while (factor[n] != 0) {
    ans.push_back(factor[n]);
    n /= factor[n];
  }
  if (n > 1) ans.push_back(n);
  return ans;
}
vector<long long int> unique(vector<long long int> x) {
  sort(x.begin(), x.end());
  set<long long int> s;
  vector<long long int> ans;
  ans.reserve(x.size());
  for (auto elem : x) s.insert(elem);
  for (auto elem : s) ans.push_back(elem);
  return ans;
}
pair<vector<long long int>, vector<long long int> > getFact(long long int n) {
  vector<long long int> fact(n + 1, 1), invfact(n + 1, 1);
  for (long long int i = 1; i <= n; i++)
    fact[i] = (i * (fact[i - 1])) % 1000000007;
  for (long long int i = 1; i <= n; i++)
    invfact[i] = (modexpo(i, 1000000007 - 2) * invfact[i - 1]) % 1000000007;
  return {fact, invfact};
}
void compress(vector<long long int>& arr, long long int n) {
  map<long long int, vector<long long int> > pos;
  for (long long int i = 1; i <= n; i++) pos[arr[i]].push_back(i);
  long long int cnt = 1;
  for (auto itr : pos) {
    for (auto elem : itr.second) arr[elem] = cnt;
    cnt++;
  }
}
bool rcomp(long long int a, long long int b) { return a > b; }
map<long long int, vector<long long int> > edges;
map<pair<long long int, long long int>, long long int> dp;
long long int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
long long int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};
long long int Dfn(long long int xs, long long int ys, long long int xa,
                  long long int ya) {
  queue<pair<long long int, pair<long long int, long long int> > > q;
  q.push({0, {xs, ys}});
  dp[{xs, ys}] = 0;
  while (!q.empty()) {
    auto elem = q.front();
    q.pop();
    for (long long int i = 0; i < 8; i++) {
      long long int newx = elem.second.first + dx[i];
      long long int newy = elem.second.second + dy[i];
      if (edges.count(newx) == 0) continue;
      if (!binary_search(edges[newx].begin(), edges[newx].end(), newy))
        continue;
      if (dp[{newx, newy}] > elem.first + 1) {
        dp[{newx, newy}] = elem.first + 1;
        q.push({elem.first + 1, {newx, newy}});
      }
    }
  }
  if (dp[{xa, ya}] < 1e8) return dp[{xa, ya}];
  return -1;
}
void solve() {
  long long int xs, ys, xa, ya;
  cin >> xs >> ys >> xa >> ya;
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int x, y, z;
    cin >> x >> y >> z;
    for (long long int j = y; j <= z; j++)
      edges[x].push_back(j), dp[{x, j}] = 1e9;
  }
  for (auto elem : edges)
    sort(edges[elem.first].begin(), edges[elem.first].end());
  long long int ans = Dfn(xs, ys, xa, ya);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
}
