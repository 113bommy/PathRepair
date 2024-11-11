#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.F << ":" << m.S << ")";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 5e3 + 100;
const int INF = 1e9;
long long A[N];
int pos[N], tak[N];
bool used[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(25);
  long long n, k, v;
  cin >> n >> k >> v;
  long long mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    if (pos[A[i] % k] == 0) {
      pos[A[i] % k] = 1;
      tak[A[i] % k] = i;
    }
    for (int j = 0; j < k; ++j) {
      if (pos[j] && !pos[(j + A[i]) % k] && tak[j] != i) {
        pos[(j + A[i]) % k] = 1;
        tak[(j + A[i]) % k] = i;
      }
    }
    mx += A[i];
  }
  if (v % k == 0) {
    vector<pair<long long, pair<long long, long long> > > vv;
    for (int i = 2; i <= n; ++i) {
      A[1] += A[i];
      vv.push_back(make_pair(INF, make_pair(i, 1)));
    }
    if (A[1] >= v) {
      cout << "YES"
           << "\n";
      vv.push_back(make_pair(v / k, make_pair(1, 2)));
      for (auto it : vv)
        cout << it.first << ' ' << it.second.first << ' ' << it.second.second
             << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
    return 0;
  }
  if (mx < v || !pos[v % k]) {
    cout << "NO"
         << "\n";
    return 0;
  }
  long long jug = tak[v % k];
  used[jug] = 1;
  vector<pair<long long, pair<long long, long long> > > vv;
  long long curr = (v - A[jug]) % k;
  if (curr < 0) curr += k;
  long long ext = -1;
  while (curr != 0) {
    assert(tak[curr] != 0);
    used[tak[curr]] = 1;
    if (ext == -1) ext = tak[curr];
    A[jug] += A[tak[curr]];
    long long p = A[tak[curr]];
    A[tak[curr]] = 0;
    vv.push_back(make_pair(INF, make_pair(tak[curr], jug)));
    curr = (curr - p) % k;
    if (curr < 0) curr += k;
  }
  assert(A[jug] % k == v % k);
  if (ext == -1) {
    if (jug != 1)
      ext = 1;
    else
      ext = n;
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i] && i != ext) {
      A[ext] += A[i];
      vv.push_back(make_pair(INF, make_pair(i, ext)));
    }
  }
  if (A[jug] < v) {
    long long zz = (A[ext] / k) * k;
    A[jug] += zz;
    vv.push_back(make_pair(zz / k, make_pair(ext, jug)));
  }
  if (A[jug] >= v) {
    cout << "YES"
         << "\n";
    if (A[jug] > v)
      vv.push_back(make_pair((A[jug] - v) / k, make_pair(jug, ext)));
    for (auto it : vv) {
      cout << it.first << ' ' << it.second.first << ' ' << it.second.second
           << "\n";
    }
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}
