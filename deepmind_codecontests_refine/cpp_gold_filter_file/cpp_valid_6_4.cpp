#include <bits/stdc++.h>
using namespace std;
template <typename val1>
void __f(const char* name, val1&& value) {
  cout << name << " = " << value << endl;
}
template <typename val1, typename... values>
void __f(const char* names, val1&& value, values&&... multiplevalue) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " = " << value << " ";
  __f(comma + 1, multiplevalue...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  set<int> tot[n + 1];
  long long alive = n;
  long long marks[n + 5];
  memset(marks, 0, sizeof marks);
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    tot[u].insert(v);
    tot[v].insert(u);
    if (u > v) {
      if (marks[v] == 0) {
        marks[v] = 1;
        alive--;
      }
    } else {
      if (marks[u] == 0) {
        marks[u] = 1;
        alive--;
      }
    }
  }
  long long q;
  cin >> q;
  long long ex = 0;
  while (q--) {
    long long a;
    cin >> a;
    if (a == 1) {
      long long u, v;
      cin >> u >> v;
      if (u > v) {
        if (marks[v] == 0) {
          marks[v] = 1;
          alive--;
        }
      } else {
        if (marks[u] == 0) {
          marks[u] = 1;
          alive--;
        }
      }
      tot[v].insert(u);
      tot[u].insert(v);
    } else if (a == 2) {
      long long u, v;
      cin >> u >> v;
      tot[u].erase(v);
      tot[v].erase(u);
      if (tot[u].size() == 0 and marks[u]) {
        marks[u] = 0;
        alive++;
      } else {
        auto a = tot[u].end();
        a--;
        if (*a < u and marks[u]) {
          marks[u] = 0;
          alive++;
        }
      }
      if (tot[v].size() == 0 and marks[v]) {
        marks[v] = 0;
        alive++;
      } else {
        auto a = tot[v].end();
        a--;
        if (*a < v and marks[v]) {
          marks[v] = 0;
          alive++;
        }
      }
    } else {
      cout << alive << endl;
    }
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
