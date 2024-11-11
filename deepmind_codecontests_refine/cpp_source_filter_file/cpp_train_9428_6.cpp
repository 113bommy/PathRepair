#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {
  out << "[" << a.first << " " << a.second << "]";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& a) {
  out << "[ ";
  for (auto& it : a) out << it << " ";
  out << "]";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const set<T>& a) {
  out << "[ ";
  for (auto& it : a) out << it << " ";
  out << "]";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {
  out << "[ ";
  for (auto& it : a) out << it << " ";
  out << "]";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {
  for (auto& it : a) out << it.first << " -> " << it.second << " | ";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {
  for (auto& it : a) out << it.first << " -> " << it.second << " | ";
  return out;
}
template <typename Arg1>
void err(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void err(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  err(comma + 1, args...);
}
void sc(int& a) { scanf("%d", &a); }
void sc(long long int& a) { scanf("%lld", &a); }
void sc(int& a, int& b) {
  sc(a);
  sc(b);
}
void sc(long long int& a, long long int& b) {
  sc(a);
  sc(b);
}
void sc(int& a, int& b, int& c) {
  sc(a, b);
  sc(c);
}
void sc(long long int& a, long long int& b, long long int& c) {
  sc(a, b);
  sc(c);
}
void prl(int a) { printf("%d\n", a); }
void prl(long long int a) { printf("%lld\n", a); }
void prl() { printf("\n"); }
void prs(int a) { printf("%d ", a); }
void prs(long long int a) { printf("%lld ", a); }
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
int mod = 1000000007;
int modpow(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b / 2;
  }
  return res % mod;
}
long long int pow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b = b / 2;
  }
  return res;
}
inline int add(int a, int b, int m = mod) {
  a += b;
  if (a >= m) a -= m;
  return a;
}
inline int mul(int a, int b, int m = mod) {
  return (int)(((long long int)a * (long long int)b) % m);
}
int color[5 * 1000 * 100 + 10], vis[5 * 1000 * 100 + 10];
vector<int> adj[5 * 1000 * 100 + 10];
pair<int, int> p[5 * 1000 * 100 + 10];
int main(int argc, char const* argv[]) {
  int n, x, y;
  sc(n);
  for (int i = 0; i < n; i++) {
    sc(x, y);
    adj[x].push_back(y);
    adj[y].push_back(x);
    p[i] = make_pair(x, y);
  }
  for (int i = 1; i <= 2 * n - 1; i += 2)
    adj[i].push_back(i + 1), adj[i + 1].push_back(i);
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    q.push(i);
    vis[i] = 1;
    color[i] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (__typeof((adj[u]).begin()) it = (adj[u]).begin();
           it != (adj[u]).end(); it++) {
        int v = *it;
        if (vis[v] == 0) {
          vis[v] = 1;
          q.push(v);
          color[v] = 3 - color[u];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", color[p[i].first], color[p[i].second]);
  }
  return 0;
}
