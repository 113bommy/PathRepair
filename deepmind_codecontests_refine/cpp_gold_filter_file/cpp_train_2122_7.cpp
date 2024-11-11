#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
void read(string& s) {
  s.clear();
  cin >> s;
}
template <typename T>
void read(vector<T>& arr, long long N) {
  arr.clear();
  arr.resize(N);
  for (long long i = 0; i < N; i++) cin >> arr[i];
}
template <typename T>
void read(vector<vector<T>>& arr, long long N, long long M) {
  arr.clear();
  arr.resize(N, vector<T>(M));
  for (long long i = 0; i < N; i++) {
    for (long long j = 0; j < M; j++) cin >> arr[i][j];
  }
}
template <typename T>
void print(vector<T>& arr) {
  for (auto it : arr) cout << it << ' ';
  cout << endl;
}
template <typename T>
void print(vector<vector<T>>& arr) {
  for (auto it : arr) {
    for (auto ut : it) cout << ut;
    cout << endl;
  }
  cout << endl;
}
struct uf {
  static const long long MAX = 105;
  long long par[MAX];
  long long size[MAX];
  void init() {
    for (long long i = 0; i < MAX; i++) {
      par[i] = -1;
      size[i] = 1;
    }
  }
  long long root(long long a) {
    if (par[a] == -1) return a;
    return par[a] = root(par[a]);
  }
  void unite(long long a, long long b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (size[a] < size[b]) {
      par[a] = b;
      size[b] += size[a];
    } else {
      par[b] = a;
      size[a] += size[b];
    }
  }
  bool same(long long a, long long b) {
    if (root(a) == root(b)) return true;
    return false;
  }
};
static bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first < b.first) return true;
  if (a.first == b.first) {
    if (a.second < b.second) return true;
  }
  return false;
}
vector<pair<long long, long long>> traverse = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long N, M;
void solve() {
  cin >> N >> M;
  vector<unordered_set<long long>> store(101);
  set<long long> comp;
  for (long long ii = 1; ii <= N; ii++) {
    long long len;
    cin >> len;
    if (len == 0) comp.insert(ii);
    vector<long long> lang;
    read(lang, len);
    for (long long j = 0; j < len; j++) {
      store[lang[j]].insert(ii);
    }
  }
  uf var;
  var.init();
  for (long long ii = 1; ii <= M; ii++) {
    vector<long long> temp;
    for (auto it = store[ii].begin(); it != store[ii].end(); it++) {
      temp.push_back(*it);
    }
    for (long long i = 0; i < (long long)temp.size() - 1; i++)
      var.unite(temp[i], temp[i + 1]);
  }
  long long cnt = 0;
  for (long long i = 1; i <= N; i++) {
    if (var.par[i] == -1 and comp.find(i) == comp.end()) cnt++;
  }
  if (cnt >= 1)
    cout << (long long)comp.size() + cnt - 1 << endl;
  else
    cout << (long long)comp.size() << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool test = 0;
  if (test) {
    long long tt;
    cin >> tt;
    while (tt > 0) {
      solve();
      tt--;
    }
  } else {
    solve();
  }
  return 0;
}
