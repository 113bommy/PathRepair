#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (a < b) swap(a, b);
  return gcd(a % b, b);
}
long long gcdextended(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1, gcd = gcdextended(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return gcd;
}
long long modinverse(long long a, long long m) {
  long long x, y;
  long long g = gcdextended(a, m, x, y);
  if (g != 1) {
    cout << "NOT POSSIBLE";
    return -1;
  } else
    return (x % m + m) % m;
}
long long po(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long pomod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long root(long long x, vector<long long> &id) {
  while (id[x] != x) {
    id[x] = id[id[x]];
    x = id[x];
  }
  return x;
}
void uni(long long x, long long y, vector<long long> &id) {
  long long a = root(x, id);
  long long b = root(y, id);
  id[a] = id[b];
}
long long mst(vector<pair<long long, pair<long long, long long> > > &e,
              vector<long long> &id) {
  long long x, y, i, j;
  long long mic = 0, c;
  for (i = 0; i < e.size(); i++) {
    x = e[i].second.first;
    y = e[i].second.second;
    c = e[i].first;
    if (root(x, id) != root(y, id)) {
      uni(x, y, id);
      mic += c;
    }
  }
  return mic;
}
bool sec(const pair<long long, long long> &a,
         const pair<long long, long long> &b) {
  return a.second > b.second;
}
void bfs(long long second, vector<vector<long long> > &v,
         vector<long long> &vis, vector<long long> &le) {
  vis[second] = 1;
  long long p, i;
  le[second] = 0;
  queue<long long> q;
  q.push(second);
  while (!q.empty()) {
    p = q.front();
    q.pop();
    for (i = 0; i < v[p].size(); i++) {
      if (!vis[v[p][i]]) {
        vis[v[p][i]] = 1;
        q.push(v[p][i]);
        le[v[p][i]] = le[p] + 1;
      }
    }
  }
}
void dfs(long long second, vector<vector<long long> > &v,
         vector<long long> &vis) {
  vis[second] = 1;
  long long i;
  for (i = 0; i < v[second].size(); i++) {
    if (!vis[v[second][i]]) dfs(v[second][i], v, vis);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long n, m, k, x, i, an = 0, c = 0, cnt;
  cin >> n >> m >> k;
  set<long long> second;
  for (i = 0; i < k; i++) {
    cin >> x;
    second.insert(x);
  }
  while (!second.empty()) {
    x = *second.begin();
    long long l = 1, h = n / k + 1, mid;
    while (l <= h) {
      mid = (l + h) / 2;
      if (x <= mid * k + c)
        h = mid - 1;
      else
        l = mid + 1;
    }
    cnt = 0;
    while (!second.empty() && *second.begin() <= l * k + c) {
      second.erase(second.begin());
      cnt++;
    }
    c += cnt;
    an++;
  }
  cout << an;
}
