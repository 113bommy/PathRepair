#include <bits/stdc++.h>
using namespace std;
bool newLine = false;
bool newLineA = false;
bool pairEndLine = false;
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& i : v) {
    in >> i;
  }
  return in;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (auto i : v) {
    out << i;
    if (!newLine) {
      out << ' ';
    } else {
      out << '\n';
    }
  }
  if (!newLine && newLineA) {
    out << '\n';
  }
  return out;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& p) {
  out << p.first << ' ' << p.second;
  if (pairEndLine) {
    cout << '\n';
  }
  return out;
}
long long gettime() {
  return chrono::high_resolution_clock::now().time_since_epoch().count() /
         (long long)1000000;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd_64(
    chrono::high_resolution_clock::now().time_since_epoch().count());
unsigned long long randnum(unsigned long long l, unsigned long long r) {
  return l + rnd_64() % (r - l + 1);
}
int mod;
bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
const int N = 2e5 + 100;
int toPrime[N];
const int A = 2e7 + 100;
char p[A];
int mult(int a, int b) { return (long long)a * b % mod; }
int geth(vector<int> v) {
  int res = 1;
  for (auto i : v) {
    res = mult(res, toPrime[i]);
  }
  return res;
}
int n, m, k;
vector<vector<int>> h;
int hashall;
int r(int pos, int a) {
  if (pos == k + 1) {
    return a == hashall;
  }
  int ans = 0;
  for (int i = 0; i < (pos); i++) {
    ans += r(pos + 1, mult(a, h[pos][i]));
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  mod = randnum(7e8, 1e9);
  while (!isPrime(mod)) mod++;
  for (auto& i : p) i = 1;
  for (int i = 2; i < A; i++) {
    if (p[i]) {
      static int pos = 0;
      toPrime[pos++] = i;
      if (pos == N) break;
      for (int j = 2 * i; j < A; j += i) {
        p[j] = false;
      }
    }
  }
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < (m); i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    g[a].push_back(make_pair(w, b));
  }
  for (auto& i : g) {
    sort(i.begin(), i.end());
  }
  vector<vector<int>> v(k + 1);
  for (auto i : g) {
    for (auto j : i) {
      v[i.size()].push_back(j.second);
    }
  }
  h.resize(k + 1);
  for (int i = 1; i <= k; i++) {
    h[i].resize(i);
    for (int start = 0; start < (i); start++) {
      vector<int> cur;
      int pos = start;
      while (pos < v[i].size()) {
        cur.push_back(v[i][pos]);
        pos += i;
      }
      h[i][start] = geth(cur);
    }
  }
  vector<int> trash(n);
  for (int i = 0; i < (n); i++) trash[i] = i;
  hashall = geth(trash);
  cout << r(1, 1);
  return 0;
}
