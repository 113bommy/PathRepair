#include <bits/stdc++.h>
using namespace std;
void sor(vector<long long> &x) { sort(x.begin(), x.end()); }
void rev(vector<long long> &x) { reverse(x.begin(), x.end()); }
long long gcd(long long x, long long y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}
list<long long> a[5];
void bfs(int src) {
  queue<int> q;
  bool *vis = new bool[5 + 1]{0};
  q.push(src);
  vis[src] = true;
  while (!q.empty()) {
    int node = q.front();
    cout << node << " ";
    q.pop();
    for (int n : a[node]) {
      if (!vis[n]) {
        q.push(n);
        vis[n] = true;
      }
    }
  }
}
long long max(long long x, long long y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}
long long min(long long x, long long y) {
  if (x > y) {
    return y;
  } else {
    return x;
  }
}
void primeFactors(long long n, vector<long long> &vec) {
  while (n % 2 == 0) {
    vec.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      vec.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) vec.push_back(n);
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
long long g(long long x) {
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return i;
    }
  }
  return 0;
}
long long countDivisors(long long n) {
  long long cnt = 0;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
long long bina(vector<long long> a, long long n, long long m) {
  long long start = 0, end = n - 1;
  long long c = 0;
  if (m >= a[n - 1]) {
    return n;
  }
  while (start <= end) {
    long long mid = (start + end) / 2;
    if (m >= a[mid]) {
      c = mid + 1;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return c;
}
long long binarySearch(vector<long long> arr, long long l, long long r,
                       long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return 0;
}
int subArraylen(long long arr[], long long n, long long K) {
  unordered_map<int, int> mp;
  mp[arr[0]] = 0;
  for (int i = 1; i < n; i++) {
    arr[i] = arr[i] + arr[i - 1];
    mp[arr[i]] = i;
  }
  int len = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] < K)
      continue;
    else {
      int x = arr[i] - K;
      if (x == 0) len = min(len, i);
      if (mp.find(x) == mp.end())
        continue;
      else {
        len = min(len, i - mp[x]);
      }
    }
  }
  return len;
}
long long prime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return 0;
}
long long nextPowerOf2(long long n) {
  long long p = 1;
  if (n && !(n & (n - 1))) return n;
  while (p < n) p <<= 1;
  return p;
}
long long countBits(long long number) { return (long long)log2(number) + 1; }
long long comb(long long c, long long n) {
  long long num = 1, d = 1;
  for (long long i = c; i > max(n, c - n); i--) {
    num *= i;
  }
  for (long long i = 2; i <= min(n, c - n); i++) {
    d *= i;
  }
  return (num / d);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  vector<long long> b(m);
  for (long long i = 0; i < n; ++i) {
    a[i] = 0;
  }
  for (long long i = 0; i < m; ++i) {
    long long q, w;
    cin >> q >> w;
    for (int i = q; i <= w; i++) {
      a[i - 1] += 1;
    }
  }
  for (long long i = 0; i < n; ++i) {
    if (a[i] == 0) {
      cout << i + 1 << " " << 0;
      return;
    } else if (a[i] == 2) {
      cout << i + 1 << " " << 2;
      return;
    }
  }
  cout << "OK";
}
vector<long long> adj[105];
long long mat[105];
void dfs(long long v, long long p) {
  mat[v] = mat[p] + 1;
  for (auto u : adj[v])
    if (u != p) dfs(u, v);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  for (long long tt = 0; tt < t; ++tt) {
    solve();
  }
  return 0;
}
