#include <bits/stdc++.h>
using namespace std;
vector<int> parse_line(string line) {
  vector<int> ret;
  int n = line.size();
  string tmp_str = "";
  int tmp_int;
  stringstream sstr;
  for (int i = 0; i < n + 1; ++i) {
    if (line[i] != ' ' and i < n) {
      tmp_str += line[i];
    } else {
      sstr << tmp_str;
      sstr >> tmp_int;
      ret.push_back(tmp_int);
      sstr.clear();
      tmp_str = "";
    }
  }
  return ret;
}
vector<long long> parse_line_ll(string line) {
  vector<long long> ret;
  int n = line.size();
  string tmp_str = "";
  long long tmp_int;
  stringstream sstr;
  for (int i = 0; i < n + 1; ++i) {
    if (line[i] != ' ' and i < n) {
      tmp_str += line[i];
    } else {
      sstr << tmp_str;
      sstr >> tmp_int;
      ret.push_back(tmp_int);
      sstr.clear();
      tmp_str = "";
    }
  }
  return ret;
}
void print_vec(vector<int> vec) {
  for (int idx = 0; idx < vec.size(); ++idx) {
    cout << vec[idx];
    if (idx < vec.size() - 1) cout << " ";
  }
  cout << endl;
}
int string_to_int(string line) {
  int ret;
  sscanf(line.c_str(), "%d", &ret);
  return ret;
}
vector<vector<int>> get_components2(int n, vector<pair<int, int>> edges) {
  vector<vector<int>> adj(n);
  for (auto e : edges) {
    adj[e.first].push_back(e.second);
    adj[e.second].push_back(e.first);
  }
  vector<vector<int>> ret;
  vector<bool> visited(n, false);
  for (int v = 0; v < n; ++v) {
    if (visited[v]) continue;
    vector<int> comp;
    queue<int> queue;
    queue.push(v);
    while (not queue.empty()) {
      int _v = queue.front();
      queue.pop();
      visited[_v] = true;
      comp.push_back(_v);
      for (auto __v : adj[_v]) {
        if (visited[__v]) continue;
        queue.push(__v);
      }
    }
    ret.push_back(comp);
  }
  return ret;
}
vector<vector<int>> get_components(int n, vector<pair<int, int>> edges) {
  vector<int> v_to_c;
  unordered_map<int, vector<int>> c_to_v;
  for (int v = 0; v < n; ++v) {
    v_to_c.push_back(v);
    c_to_v[v] = {v};
  }
  for (auto e : edges) {
    int c_0 = v_to_c[e.first], c_1 = v_to_c[e.second];
    if (c_0 == c_1) continue;
    if (c_to_v[c_0].size() < c_to_v[c_1].size()) {
      int tmp = c_0;
      c_0 = c_1;
      c_1 = tmp;
    }
    for (auto v : c_to_v[c_1]) {
      c_to_v[c_0].push_back(v);
      v_to_c[v] = c_0;
    }
    c_to_v.erase(c_1);
  }
  vector<vector<int>> ret;
  for (auto it : c_to_v) {
    ret.push_back(it.second);
  }
  return ret;
}
long long choose(int n, int m) {
  if (n == m) return 1;
  if (n < m) return 0;
  long long ret = 1;
  for (int _n = n; _n >= n - m + 1; --_n) {
    ret *= _n;
  }
  for (int _m = 2; _m <= m; ++_m) {
    ret /= _m;
  }
  return ret;
}
const long long MOD = 1e+9 + 7;
class linked_node {
 public:
  linked_node(int data) {
    data_ = data;
    next_ = NULL;
    prev_ = NULL;
  }

 public:
  int data_;
  linked_node* next_;
  linked_node* prev_;
};
void beingawesomeism() {
  string line;
  int test_cases;
  getline(cin, line);
  sscanf(line.c_str(), "%d", &test_cases);
  vector<int> ret;
  for (int t = 0; t < test_cases; ++t) {
    int r, c;
    getline(cin, line);
    sscanf(line.c_str(), "%d %d", &r, &c);
    vector<string> grid;
    bool Aexist = false, Pexist = true;
    for (int _r = 0; _r < r; ++_r) {
      getline(cin, line);
      for (int _c = 0; _c < c; ++_c) {
        if (line[_c] == 'A') Aexist = true;
        if (line[_c] == 'P') Pexist = true;
      }
      grid.push_back(line);
    }
    if (not Pexist) {
      ret.push_back(0);
      continue;
    }
    if (not Aexist) {
      ret.push_back(-1);
      continue;
    }
    bool upper = true, lower = true;
    for (int _c = 0; _c < c; ++_c) {
      if (grid[0][_c] == 'P') upper = false;
      if (grid[r - 1][_c] == 'P') lower = false;
    }
    if (upper or lower) {
      ret.push_back(1);
      continue;
    }
    bool left = true, right = true;
    for (int _r = 0; _r < r; ++_r) {
      if (grid[_r][0] == 'P') left = false;
      if (grid[_r][c - 1] == 'P') right = false;
    }
    if (left or right) {
      ret.push_back(1);
      continue;
    }
    if (grid[0][0] == 'A' or grid[0][c - 1] == 'A' or grid[r - 1][0] == 'A' or
        grid[r - 1][c - 1] == 'A') {
      ret.push_back(2);
      continue;
    }
    bool full = false;
    for (int _r = 1; _r < r - 1; ++_r) {
      full = true;
      for (int _c = 0; _c < c; ++_c) {
        if (grid[_r][_c] == 'P') full = false;
      }
      if (full) break;
    }
    if (full) {
      ret.push_back(2);
      continue;
    }
    full = false;
    for (int _c = 1; _c < c - 1; ++_c) {
      full = true;
      for (int _r = 0; _r < r; ++_r) {
        if (grid[_r][_c] == 'P') full = false;
      }
      if (full) break;
    }
    if (full) {
      ret.push_back(2);
      continue;
    }
    upper = false, lower = false;
    for (int _c = 1; _c < c - 1; ++_c) {
      if (grid[0][_c] == 'A') upper = true;
      if (grid[r - 1][_c] == 'A') lower = true;
    }
    if (upper or lower) {
      ret.push_back(3);
      continue;
    }
    left = false, right = false;
    for (int _r = 1; _r < r - 1; ++_r) {
      if (grid[_r][0] == 'A') left = true;
      if (grid[_r][c - 1] == 'A') right = true;
    }
    if (left or right) {
      ret.push_back(3);
      continue;
    }
    ret.push_back(4);
  }
  for (auto _ret : ret) {
    if (_ret == -1) {
      cout << "MORTAL" << endl;
    } else {
      cout << _ret << endl;
    }
  }
}
int main() {
  beingawesomeism();
  return 0;
}
