#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = (long long)(998244353)) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = (long long)(998244353)) {
  return (a % p + b % p) % p;
}
long long neg(long long a, long long p = (long long)(998244353)) {
  return (p - (a % p)) % p;
}
long long sub(long long a, long long b, long long p = (long long)(998244353)) {
  return add(a, neg(b));
}
long long fpow(long long x, long long y) {
  long long res = 1;
  x = x % (long long)(998244353);
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1LL) res = (res * x) % (long long)(998244353);
    y = y >> 1LL;
    x = (x * x) % (long long)(998244353);
  }
  return res;
}
long long inv(long long a, long long p = (long long)(998244353)) {
  return fpow(a, p - 2);
}
bool sa(const pair<long long, long long> &a,
        const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool fd(const pair<long long, long long> &a,
        const pair<long long, long long> &b) {
  return (a.first > b.first);
}
bool sd(const pair<long long, long long> &a,
        const pair<long long, long long> &b) {
  return (a.second > b.second);
}
long long dx[4] = {0, 0, 1, -1};
long long dy[4] = {1, -1, 0, 0};
bool valid(long long x, long long y, long long n, long long m) {
  if (x < 0 || y < 0) {
    return false;
  } else if (x >= n || y >= m) {
    return false;
  } else
    return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  T = 1;
  for (long long t = 1; t < T + 1; t++) {
    long long n, m, ans, val, x, y;
    cin >> n >> m;
    long long topic[n + 5], s[n + 5];
    vector<long long> adj[n + 5];
    unordered_map<long long, long long> mpp;
    vector<pair<long long, long long> > v;
    for (long long i = 0; i < m; i++) {
      cin >> x >> y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
    for (long long i = 1; i < n + 1; i++) {
      s[i] = 0;
      cin >> topic[i];
      v.emplace_back(make_pair(topic[i], i));
    }
    for (long long i = 1; i < n + 1; i++) {
      for (auto next : adj[i]) {
        if (topic[next] > topic[i]) {
          continue;
        } else {
          if (mpp[topic[next]] == 0) {
            s[i] += topic[next];
            mpp[topic[next]] = 1;
          }
        }
      }
      mpp.clear();
    }
    for (long long i = 1; i < n + 1; i++) {
      val = topic[i] - 1;
      ans = (val * (val + 1)) / 2;
      if (s[i] != ans) {
        cout << "-1";
        return 0;
      }
    }
    sort(v.begin(), v.end());
    for (long long i = 0; i < (long long)v.size(); i++) {
      cout << v[i].second << " ";
    }
    cout << "\n";
  }
  return 0;
}
