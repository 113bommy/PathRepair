#include <bits/stdc++.h>
using namespace std;
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
void read(vector<T>& v, long long n) {
  v.clear();
  v.resize(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
}
template <typename T>
void read(vector<pair<T, T>>& v, long long n) {
  v.clear();
  v.resize(n);
  for (long long i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
}
template <typename T>
void read(vector<vector<T>>& v, long long n, long long m) {
  v.clear();
  v.resize(n, vector<T>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> v[i][j];
  }
}
template <typename T>
void print(vector<T>& v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << endl;
}
template <typename T>
void print(vector<pair<T, T>>& v) {
  for (long long i = 0; i < v.size(); i++)
    cout << v[i].first << ' ' << v[i].second << endl;
  cout << endl;
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = 0; j < v[i].size(); j++) cout << v[i][j];
    cout << endl;
  }
}
template <typename T>
void print(vector<vector<T>>& v, long long n) {
  for (long long i = 1; i <= n; i++) {
    cout << i << ": ";
    for (long long j = 0; j < v[i].size(); j++) cout << v[i][j] << ' ';
    cout << endl;
  }
}
struct uf {
  vector<long long> par, size;
  void init(long long n) {
    par.resize(n, -1);
    size.resize(n, 1);
  }
  long long find(long long a) {
    if (par[a] == -1) return a;
    return par[a] = find(par[a]);
  }
  void unite(long long a, long long b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] < size[b]) {
      par[a] = b;
      size[b] += size[a];
    } else {
      par[b] = a;
      size[a] += size[b];
    }
  }
  bool isCycle(long long a, long long b) {
    if (find(a) == find(b)) return true;
    return false;
  }
};
static bool comp(vector<long long>& a, vector<long long>& b) {
  if (a[0] < b[0])
    return true;
  else if (a[0] == b[0])
    return a[1] > b[1];
  return false;
}
long long mod = 1e9 + 7;
long long lim = 2 * 1e5 + 5;
void sol() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v(n + 1);
  read(v, n);
  char dir = 'N';
  long long ret = 0;
  for (long long i = 1; i < n; i++) {
    if (dir == 'N') {
      if (v[i + 1].first > v[i].first)
        dir = 'E';
      else {
        dir = 'W';
        ret++;
      }
    } else if (dir == 'S') {
      if (v[i + 1].first < v[i].first)
        dir = 'W';
      else {
        dir = 'E';
        ret++;
      }
    } else if (dir == 'E') {
      if (v[i + 1].second < v[i].second)
        dir = 'S';
      else {
        dir = 'N';
        ret++;
      }
    } else if (dir == 'W') {
      if (v[i + 1].second > v[i].second)
        dir = 'N';
      else {
        dir = 'S';
        ret++;
      }
    }
  }
  cout << ret << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  bool t = false;
  if (t) {
    long long n;
    cin >> n;
    while (n--) {
      sol();
    }
  } else {
    sol();
  }
  return 0;
}
