#include <bits/stdc++.h>
using namespace std;
class customIO {
 public:
  istream& in;
  ostream& out;
  customIO(istream& _in, ostream& _out) : in(_in), out(_out) {}
  string next() {
    string s;
    in >> s;
    return s;
  }
  double nextDouble() { return stod(next()); }
  int nextInt() { return stoi(next()); }
  long long nextLong() { return stoll(next()); }
  template <typename T>
  void print(T t) {
    out << t;
  }
  template <typename T, typename... U>
  void print(T t, U... u) {
    out << t;
    print(u...);
  }
  template <typename T, typename... U>
  void println(T t, U... u) {
    print(t, u..., "\n");
  }
  void println() { print("\n"); }
};
int n;
int cost[200005];
bool vis[200005];
vector<vector<int> > graph;
vector<int> _stack;
map<int, int> instack;
bool f = false;
class CF1027D {
 public:
  void solve(customIO& io) {
    n = io.nextInt();
    graph.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
      cost[i] = io.nextInt();
    }
    int x;
    for (int i = 1; i <= n; ++i) {
      x = io.nextInt();
      if (i != x) {
        graph[i].push_back(x);
      }
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
      if (vis[i] == 0) {
        f = false;
        vis[i] = 1;
        _stack.clear();
        _stack.push_back(i);
        instack.clear();
        instack[i] = true;
        int ret = dfs(i);
        if (f) ret = 0;
        res += ret;
      }
    }
    io.println(res);
    return;
  }
  int dfs(int x) {
    int res = cost[x];
    assert(graph[x].size() <= 1);
    if (graph[x].size() == 0) return res;
    int nxt = graph[x][0];
    assert(nxt <= n);
    if (vis[nxt] == 1) {
      if (instack[nxt] == 1) {
        for (int j = (int)_stack.size() - 1; j >= 0; --j) {
          if (_stack[j] == nxt) {
            int p = cost[x];
            for (int k = j; j < _stack.size(); ++j) {
              p = min(cost[_stack[k]], p);
            }
            return p;
          }
        }
        assert(false);
      } else {
        f = true;
        return 1e9;
      }
    } else {
      vis[nxt] = 1;
      instack[nxt] = 1;
      _stack.push_back(nxt);
      res = dfs(nxt);
      _stack.pop_back();
      instack[nxt] = false;
    }
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(20);
  istream& in(std::cin);
  ostream& out(std::cout);
  customIO io(in, out);
  CF1027D solver;
  solver.solve(io);
  return 0;
}
