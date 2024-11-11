#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + "," +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug(T...);
}
struct fast_power {
  long long integer(long long n, long long e,
                    long long my_mod = 9223372036854775807LL) {
    long long ans = 1;
    while (e) {
      if (e & 1)
        ans = (ans * n) % my_mod, e--;
      else
        n = (n * n) % my_mod, e >>= 1;
    }
    return ans;
  }
  long long matrix(vector<vector<long long>> &n, long long e,
                   long long my_mod = 9223372036854775807LL);
};
struct euclidean {
  int gcdi(int a, int b) { return b ? gcdi(b, a % b) : a; }
  double gcdf(double a, double b, double accuracy) {
    return b <= accuracy ? a : gcdf(b, fmod(a, b), accuracy);
  }
};
const int INF = 0x3f3f3f3f;
const int maxn = 500 + 5;
const int maxm = 26 * 26 + 5;
char s[maxn][maxn];
int a[maxn][maxm], d[maxn][maxm], f[maxn][maxm];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) cin >> s[i];
  memset(d, INF, sizeof(d));
  for (int i = 0; i < m; i++) {
    for (int q = 0; q < 26 * 26; q++) {
      a[i][q] = 0;
      int f1 = q / 26, f2 = q % 26;
      if (f1 == f2) {
        a[i][q] = INF;
        continue;
      }
      for (int e = 0; e < n; e++) {
        if (e % 2 == 0 && s[i][e] - 'a' != f1)
          a[i][q]++;
        else if (e % 2 && s[i][q] - 'a' != f2)
          a[i][q]++;
      }
    }
    if (i == 0)
      memcpy(d[0], a[0], sizeof(a[0]));
    else {
      for (int q = 0; q < 26 * 26; q++) {
        int f1 = q / 26, f2 = q % 26;
        if (f1 == f2) continue;
        for (int e = 0; e < 26 * 26; e++) {
          int x1 = e / 26, x2 = e % 26;
          if (x1 == f1 || x2 == f2) continue;
          if (x1 == x2) continue;
          if (d[i - 1][e] + a[i][q] < d[i][q])
            f[i][q] = e, d[i][q] = d[i - 1][e] + a[i][q];
        }
      }
    }
  }
  int ans = INF, pos2;
  for (int q = 0; q < 26 * 26; q++)
    if (d[m - 1][q] < ans) ans = d[m - 1][q], pos2 = q;
  vector<int> p;
  p.push_back(pos2);
  for (int i = m - 1; i >= 1; i--) {
    pos2 = f[i][pos2];
    p.push_back(pos2);
  }
  cout << ans << endl;
  for (int i = p.size() - 1; i >= 0; i--) {
    char f1 = p[i] / 26 + 'a', f2 = p[i] % 26 + 'a';
    for (int q = 0; q < n; q++) {
      if (q % 2 == 0)
        cout << f1;
      else
        cout << f2;
    }
    cout << endl;
  }
  return 0;
}
