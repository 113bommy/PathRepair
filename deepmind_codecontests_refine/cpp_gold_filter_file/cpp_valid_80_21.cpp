#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
auto clk = clock();
const long double PI2 = acos(-1) / 2.0l;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int dx8[] = {-1, -1, -1, 0, 1, 1, 1, 0},
          dy8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MAXN = 100010;
long long Gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return Gcd(b, a % b);
}
long long Max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long Min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
void kickstartFormat() {
  static int tno = 1;
  cout << "Case #" << tno++ << ": ";
}
void printvector(std::vector<long long> v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << "" << endl;
}
void printarray(long long a[], long long n) {
  for (long long i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << "" << endl;
}
long long findlcm(vector<long long> arr, long long n) {
  long long ans = arr[0];
  for (int i = 1; i < n; i++) ans = (((arr[i] * ans)) / (Gcd(arr[i], ans)));
  return ans;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long lowerbound(long long k, vector<long long> v) {
  long long l = 0;
  long long size = v.size();
  long long r = size - 1;
  long long mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] < k)
      l = mid + 1;
    else {
      r = mid - 1;
    }
  }
  return l;
}
long long upperbound(long long k, vector<long long> v) {
  long long l = 0;
  long long size = v.size();
  long long r = size - 1;
  long long mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] > k)
      r = mid - 1;
    else {
      l = mid + 1;
    }
  }
  return l;
}
long long spf[MAXN];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++) spf[i] = i;
  for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (int i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long n, m;
vector<long long> shortPath(vector<pair<long long, long long>> v[],
                            long long src, long long V = 0) {
  set<pair<long long, long long>> setds;
  long long sizee = V;
  long long IN = 1000000000000000000;
  vector<long long> dist(sizee, IN);
  vector<bool> vis(sizee, false);
  setds.insert(make_pair(0, src));
  dist[src] = 0;
  while (!setds.empty()) {
    pair<long long, long long> tmp = *(setds.begin());
    setds.erase(setds.begin());
    long long u = tmp.second;
    if (vis[u]) continue;
    vis[u] = true;
    vector<pair<long long, long long>>::iterator i;
    for (auto i = v[u].begin(); i != v[u].end(); ++i) {
      long long v = (*i).first;
      long long weight = (*i).second;
      if (dist[v] > dist[u] + weight) {
        if (dist[v] != 1000000000000000000)
          setds.erase(setds.find(make_pair(dist[v], v)));
        dist[v] = dist[u] + weight;
        setds.insert(make_pair(dist[v], v));
      }
    }
  }
  return dist;
}
long long root(long long a[], long long r) {
  if (a[r] == r) {
    return r;
  } else {
    long long x = root(a, a[r]);
    a[r] = x;
    return x;
  }
}
void unio(long long a[], long long size[], long long x, long long y) {
  x = root(a, x);
  y = root(a, y);
  if (x == y) {
    return;
  }
  if (size[x] >= size[y]) {
    a[y] = x;
    size[x] += size[y];
  } else {
    a[x] = y;
    size[y] += size[x];
  }
}
const long long N = 100005;
void CV(long long txt) {
  cin >> n;
  string s;
  cin >> s;
  long long l1, r1, l2, r2;
  long long mid = (n + 1) / 2;
  long long ind = -1;
  for (long long i = mid; i < n; i++) {
    if (s[i] == '0') {
      ind = i;
      break;
    }
  }
  if (ind != -1) {
    cout << 1 << " " << ind + 1 << " ";
    cout << 1 << " " << ind << endl;
    cerr << endl;
    return;
  }
  if (s[mid - 1] == '1') {
    cout << mid << " " << n - 1 << " ";
    cout << mid + 1 << " " << n << endl;
    cerr << endl;
    return;
  }
  cout << mid << " " << n << " ";
  cout << mid + 1 << " " << n << endl;
  cerr << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x68 = 1;
  cin >> x68;
  for (long long vi = 1; vi <= x68; vi++) {
    CV(vi);
  }
  return 0;
}
