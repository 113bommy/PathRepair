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
const int maxn = 100 + 5;
char s[maxn][maxn] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, a, b, c;
  cin >> m >> n >> a >> b >> c;
  int ok = 1;
  if ((m * n) % 2)
    ok = 0;
  else {
    for (int i = 0; i < m; i += 2)
      for (int q = 0; q < n; q += 2) {
        if (c == 0) break;
        if (i + 1 >= m || q + 1 >= n) continue;
        for (int e = i; e < i + 2; e++)
          for (int r = q; r < q + 2; r++) s[e][r] = 'c';
        c--;
      }
    if (n & 1) {
      for (int i = 0; i < m; i += 2)
        if (a > 0 && s[i][n - 1] == 0 && i + 1 < m && s[i + 1][n - 1] == 0)
          s[i][n - 1] = s[i + 1][n - 1] = 'b', b--;
    }
    if (m & 1) {
      for (int i = 0; i < n; i += 2)
        if (b > 0 && s[m - 1][i] == 0 && i + 1 < n && s[m - 1][i + 1] == 0)
          s[m - 1][i] = s[m - 1][i + 1] = 'a', a--;
    }
    for (int i = 0; i < m; i += 2)
      for (int q = 0; q < n; q += 2)
        if (s[i][q] == 0) {
          if (i + 1 >= m || q + 1 >= n) continue;
          char str;
          if (a >= 2)
            str = 'a', a -= 2;
          else if (b >= 2)
            str = 'b', b -= 2;
          else
            break;
          for (int e = i; e < i + 2; e++)
            for (int r = q; r < q + 2; r++) s[e][r] = str;
        }
  }
  for (int i = 0; i < m; i++)
    for (int q = 0; q < n; q++)
      if (s[i][q] == 0) ok = 0;
  if (ok) {
    int vis[maxn][maxn] = {0};
    int ans[maxn][maxn] = {0};
    for (int i = 0; i < m; i++)
      for (int q = 0; q < n; q++)
        if (!vis[i][q]) {
          int arr[26] = {0};
          if (i - 1 >= 0) arr[ans[i - 1][q]] = 1;
          if (q - 1 >= 0) arr[ans[i][q - 1]] = 1;
          if (i - 1 >= 0 && (s[i][q] == 'c' || s[i][q] == 'a'))
            arr[ans[i - 1][q + 1]] = 1;
          if (q - 1 >= 0 && (s[i][q] == 'c' || s[i][q] == 'b'))
            arr[ans[i + 1][q - 1]] = 1;
          if (s[i][q] == 'a') arr[ans[i][q + 2]] = 1;
          int num;
          for (int e = 0; e < 26; e++)
            if (!arr[e]) {
              num = e;
              break;
            }
          if (s[i][q] == 'a') {
            vis[i][q] = vis[i][q + 1] = 1;
            ans[i][q] = ans[i][q + 1] = num;
          } else if (s[i][q] == 'b') {
            vis[i][q] = vis[i + 1][q] = 1;
            ans[i][q] = ans[i + 1][q] = num;
          } else {
            vis[i][q] = vis[i][q + 1] = vis[i + 1][q] = vis[i + 1][q + 1] = 1;
            ans[i][q] = ans[i][q + 1] = ans[i + 1][q] = ans[i + 1][q + 1] = num;
          }
        }
    for (int i = 0; i < m; i++) {
      for (int q = 0; q < n; q++) cout << (char)(ans[i][q] + 'a');
      cout << endl;
    }
  } else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
