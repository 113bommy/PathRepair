#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
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
  for (const auto& x : v) {
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
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int maxn = 1e6 + 5;
pair<int, int> e[maxn];
bool vis[maxn];
int in[maxn], in2[maxn];
int main() {
  srand(time(NULL));
  int n, m;
  scanf("%d %d", &n, &m);
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    e[i] = {u, v};
    in[u]++;
    in[v]++;
  }
  random_shuffle(e + 1, e + 1 + m);
  for (int i = 1; i <= n; i++) {
    in2[i] = (in[u] - 1) / 2 + 1;
  }
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int u = e[i].first;
    int v = e[i].second;
    if (in[u] - 1 >= in2[u] && in[v] - 1 >= in2[v]) {
      vis[i] = 1;
      in[u]--;
      in[v]--;
      cnt++;
    }
  }
  cout << m - cnt << endl;
  for (int i = 1; i <= m; i++) {
    if (vis[i] == 0) {
      printf("%d %d\n", e[i].first, e[i].second);
    }
  }
  return 0;
}
