#include <bits/stdc++.h>
using namespace std;
class Graph {
 public:
  vector<vector<int> > adj_list;
  Graph(int n) : adj_list(vector<vector<int> >(n)) {}
  void add_edge(int u, int v, bool bidirectional = true) {
    adj_list[u].push_back(v);
    if (bidirectional) {
      adj_list[v].push_back(u);
    }
  }
};
void print_err() { cerr << "\n"; }
template <class T, class... Arg>
void print_err(T x, Arg &&...args) {
  cerr << x << " ";
  print_err(args...);
}
template <class T>
void print_container(T &cont) {
  for (auto iter : cont) {
    cerr << iter << " ";
  }
  cerr << "\n";
}
void in() {}
template <class T, class... Arg>
void in(T &x, Arg &&...args) {
  cin >> x;
  in(args...);
}
template <class T>
void in_c(T &container, int start, int end) {
  for (int i = start; i < end; ++i) {
    cin >> container[i];
  }
}
inline void kick_temp(int test) { cout << "Case #" << test << ": "; }
vector<int> d4x{0, 0, 1, -1};
vector<int> d4y{-1, 1, 0, 0};
vector<int> d8x{0, 0, 1, -1, 1, 1, -1, -1};
vector<int> d8y{1, -1, 0, 0, -1, 1, 1, -1};
void solve(int test) {
  ;
  int i, j, n, m;
  in(n, m);
  string h(m, '#');
  string d(m - 1, '.');
  bool left = false;
  for (i = 0; i < n; ++i) {
    if (i & 1) {
      if (left) {
        cout << "#";
        cout << d;
      } else {
        cout << d;
        cout << "#";
      }
      left = !left;
    } else {
      cout << h;
    }
    cout << "\n";
  }
}
int main() {
  int i = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve(i);
  return 0;
}
