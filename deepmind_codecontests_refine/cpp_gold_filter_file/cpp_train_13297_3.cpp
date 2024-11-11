#include <bits/stdc++.h>
using namespace std;
const int N = 4e7 + 10;
bool isprime[N];
vector<int> prime;
const int M = 1e5 + 10;
int dis[55][M];
vector<int> factor[55];
bool vis[M];
vector<pair<int, long long> > edge[M];
map<long long, int> ma;
void init(int n) {
  memset(isprime, true, sizeof(isprime));
  isprime[1] = false;
  for (int i = (2); i < (n + 1); i++) {
    if (isprime[i]) prime.push_back(i);
    for (int j = 0; j < (int)prime.size() && i * prime[j] <= n; j++) {
      isprime[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
}
int cnt = 0;
void dij(int *dis) {
  priority_queue<pair<int, long long>, vector<pair<int, long long> >,
                 greater<pair<int, long long> > >
      q;
  memset(vis, false, sizeof(false));
  for (int i = (0); i < (M); i++) dis[i] = 1e9;
  dis[0] = 0;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    if (vis[x]) continue;
    for (auto i : edge[x]) {
      if (dis[i.first] > dis[x] + i.second) {
        dis[i.first] = dis[x] + i.second;
        q.push(make_pair(dis[i.first], i.first));
      }
    }
  }
}
int solve(long long x) {
  if (ma.find(x) != ma.end()) {
    return ma[x];
  }
  cnt++;
  ma[x] = cnt;
  for (auto i : prime) {
    if ((long long)i * i > x) break;
    if (x % i == 0) {
      while (x % i == 0) {
        x /= i;
      }
      factor[cnt].push_back(i);
    }
  }
  if (x != 1) factor[cnt].push_back(x);
  if ((int)factor[cnt].size() >= 3) {
    int p = factor[cnt][0];
    for (int i = (0); i < (p + 1); i++) edge[i].clear();
    for (int i = (0); i < (p); i++) {
      for (auto j : factor[cnt]) {
        edge[i].push_back(make_pair((i + j) % p, j));
      }
    }
    dij(dis[cnt]);
  }
  return cnt;
}
long long qpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init(4e7);
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    int id = solve(k);
    if ((int)factor[id].size() == 0) {
      cout << "NO"
           << "\n";
      continue;
    }
    if ((int)factor[id].size() == 1) {
      if (n % k == 0) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
      continue;
    } else if ((int)factor[id].size() == 2) {
      int tmp = n % factor[id][1] *
                qpow(factor[id][0], factor[id][1] - 2, factor[id][1]) %
                factor[id][1];
      if ((__int128)factor[id][0] * tmp <= n) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
      continue;
    } else {
      int p = factor[id][0];
      if (dis[id][n % p] <= n)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
