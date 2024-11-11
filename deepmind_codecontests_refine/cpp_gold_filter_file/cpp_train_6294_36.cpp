#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void printVec(const T &v, char sep = ' ') {
  for (auto &i : v) cout << i << sep;
}
template <typename T>
void printVecPair(const T &v, char sep = ' ') {
  for (auto &i : v) cout << i.first << " " << i.second << sep;
}
vector<vector<int> > graph(4);
int visited[1000] = {false};
void dfs(int i) {
  visited[i] = true;
  for (int e : graph[i]) {
    if (!visited[e]) dfs(e);
  }
  switch (i) {
    case 1:
      cout << 'A';
      break;
    case 2:
      cout << 'B';
      break;
    case 3:
      cout << 'C';
      break;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 3;
  unordered_map<char, int> hash;
  hash['A'] = 1;
  hash['B'] = 2;
  hash['C'] = 3;
  while (n--) {
    string cnd;
    cin >> cnd;
    if (cnd[1] == '>') {
      ;
      ;
      graph[hash[cnd[0]]].push_back(hash[cnd[2]]);
    } else {
      graph[hash[cnd[2]]].push_back(hash[cnd[0]]);
    }
  }
  bool isC = true;
  for (int i = 1; i < 4; i++) {
    if (graph[i].size() == 0) {
      isC = false;
      break;
    }
  }
  if (isC) {
    cout << "Impossible";
    return 0;
  }
  for (int i = 1; i <= 3; i++)
    if (!visited[i]) dfs(i);
  return 0;
}
