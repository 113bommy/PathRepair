#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
const long long MOD = (int)1e9 + 7;
const long long INF = 2e18 + 5;
struct hashLL {
  size_t operator()(long long x) const {
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return x;
  }
};
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
template <class T>
void coutend(T arg) {
  cout << arg << '\n';
}
template <class T>
void coutsp(T arg) {
  cout << arg << ' ';
}
template <class T>
void coutarrsp(T arr, int l, int r) {
  for (int i = l; i <= r; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}
template <class T>
void coutarr(T arr, int l, int r) {
  for (int i = l; i <= r; i++) {
    cout << arr[i];
  }
  cout << '\n';
}
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long distsq(long long x1, long long y1, long long x2, long long y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
const int N = 500001;
long long n, m, k, t, u, v;
long long fact[2 * N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  unordered_map<int, int> ids;
  unordered_map<int, set<int>> idsToSet;
  int curr = 0;
  for (int i = 1; i <= (m); i++) {
    ids[i] = curr;
    idsToSet[curr].emplace(i);
  }
  fact[1] = 1;
  for (long long i = 2; i < 2 * N; i++) fact[i] = (i * fact[i - 1]) % MOD;
  curr++;
  for (int i = 0; i < (n); i++) {
    cin >> k;
    unordered_map<int, int> cnts;
    unordered_map<int, unordered_map<int, vector<int>>> cntsToPrevToTypes;
    for (int i = 0; i < (k); i++) {
      cin >> u;
      cnts[u]++;
    }
    for (auto& p : cnts) {
      cntsToPrevToTypes[p.second][ids[p.first]].push_back(p.first);
    }
    for (auto& p : cntsToPrevToTypes) {
      for (auto& pp : p.second) {
        long long pid = pp.first;
        for (long long tp : pp.second) {
          idsToSet[pid].erase(tp);
          idsToSet[curr].emplace(tp);
          ids[tp] = curr;
        }
        if (idsToSet[pid].empty()) idsToSet.erase(pid);
        curr++;
      }
    }
  }
  long long ans = 1;
  for (auto& p : idsToSet) {
    long long sz = p.second.size();
    ans = (ans * fact[sz]) % MOD;
  }
  coutend(ans);
}
