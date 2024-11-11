#include <bits/stdc++.h>
using namespace std;
template <class T>
void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
template <class T>
T read_value(string s) {
  T result;
  istringstream sin(s);
  sin >> result;
  return result;
}
string read_line() {
  string ret_val;
  getline(std::cin, ret_val);
  return ret_val;
}
template <class T>
void init_array(T *arr, int size, T value) {
  for (int i = 0; i < size; i++) arr[i] = value;
}
template <class T>
inline T gcd(T a, T b) {
  return (!a) ? b : gcd(b % a, a);
}
template <class T>
inline T mod(T a, T p) {
  a %= p;
  return (a < 0) ? a + p : a;
}
template <class T>
inline int num_bits(T n) {
  return (!n) ? 0 : 1 + numbits(n & (n - 1));
}
template <class T>
inline T inverse(T a, T m) {
  a = mod<T>(a, m);
  return (a == 1) ? 1 : mod((1 - m * inverse(m % a, a)) / a, m);
}
template <class T>
inline bool is_prime(T a) {
  T lim = (T)sqrt((double)a);
  for (T i = 2; i <= T(lim + 1E-9); i++)
    if (a % i == 0) return false;
  return true;
}
template <class T>
inline T power(T a, T p, T mod) {
  if (!p) return 1;
  T temp = power(a, p >> 1, mod);
  temp = (temp * temp) % mod;
  if (p & 1) temp = (temp * a) % mod;
  return temp;
}
void get_primes(int start, int end, vector<int> &vi) {
  int *p = new int[end + 1];
  init_array<int>(p, end + 1, 0);
  p[1] = 1;
  for (int i = 2; i <= end; i++) {
    if (!p[i]) {
      if (i >= start) vi.push_back(i);
      for (int j = 2 * i; j <= end; j += i) p[j] = 1;
    }
  }
  delete[] p;
}
bool dfs(int current, int final, int total, int *visited, int **edges,
         bool flow) {
  if (current == final) return true;
  if (visited[current]) return false;
  visited[current] = true;
  for (int i = 0; i < total; i++)
    if (edges[current][i] && dfs(i, final, total, visited, edges, flow)) {
      if (flow) {
        edges[current][i]--;
        edges[i][current]++;
      }
      return true;
    }
  return false;
}
int flow(int in, int out, int total, int **edges) {
  int result = 0;
  int *visited = new int[total];
  while (init_array<int>(visited, total, 0),
         dfs(in, out, total, visited, edges, true))
    result++;
  delete[] visited;
  return result;
}
void create_set(int x, int *P, int *rank) {
  P[x] = x;
  rank[x] = 0;
}
int find_set(int x, int *P) {
  if (x != P[x]) P[x] = find_set(P[x], P);
  return P[x];
}
bool merge_sets(int x, int y, int *P, int *rank) {
  int Px = find_set(x, P);
  int Py = find_set(y, P);
  if (Px == Py) return false;
  if (rank[Px] > rank[Py])
    P[Py] = Px;
  else
    P[Px] = Py;
  if (rank[Px] == rank[Py]) rank[Py]++;
  return true;
}
template <typename T>
int read_cum_freq(int index, T *tree) {
  int sum = 0;
  while (index) {
    sum += tree[index];
    index -= (index & -index);
  }
  return sum;
}
template <typename T>
void upd_freq(int index, int mxIndex, int value, T *tree) {
  while (index <= mxIndex) {
    tree[index] += value;
    index += (index & -index);
  }
}
template <typename T>
int read_freq(int index, T *tree) {
  return read_cum_freq(index, tree) - read_cum_freq(index - 1, tree);
}
void build_failure_function(const string &str, int *temp_arr) {
  temp_arr[0] = temp_arr[1] = 0;
  for (int i = 2; i <= ((int)(str).size()); i++) {
    temp_arr[i] = -1;
    for (int ind = temp_arr[i - 1]; temp_arr[i] == -1; ind = temp_arr[ind]) {
      if (str[ind] == str[i - 1]) {
        temp_arr[i] = ind + 1;
      } else if (ind == 0) {
        temp_arr[i] = 0;
      }
    }
  }
}
void KMP(const string &text, const string &pattern, int *res) {
  int *temp_arr = new int[((int)(pattern).size()) + 1];
  build_failure_function(pattern, temp_arr);
  int i = 0;
  int ind = 0;
  while (i < ((int)(text).size())) {
    if (text[i] == pattern[ind]) {
      res[i] = ++ind;
      if (res[i] == ((int)(pattern).size())) {
        ind = temp_arr[ind];
      }
      i++;
    } else if (ind == 0) {
      res[i++] = 0;
    } else {
      ind = temp_arr[ind];
    }
  }
  delete[] temp_arr;
}
void setup(int value, string name) {
  string name_in = name + ".in";
  string name_out = name + ".out";
  freopen(name_in.c_str(), "r", stdin);
  if (value) {
    freopen(name_out.c_str(), "w", stdout);
  }
}
struct cycle {
  vector<int> pos;
  vector<int> ord;
  cycle(const vector<int> &pos, const vector<int> &ord) {
    this->pos = pos;
    this->ord = ord;
  }
};
map<int, vector<cycle> > dict;
void out(const vector<int> &vi) {
  for (int i = 0; i < vi.size(); i++) std::cout << vi[i] + 1 << " ";
}
bool vis[100001];
int main() {
  int n;
  std::cin >> n;
  vector<int> vi(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vi[i];
    vi[i]--;
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    vector<int> pos, ord;
    int cur_pos = i;
    while (!vis[i]) {
      cur_pos = vi[cur_pos];
      vis[cur_pos] = true;
      pos.push_back(cur_pos);
      ord.push_back(vi[cur_pos]);
      if (pos.size() == 5 || vis[i]) {
        if (vis[i]) {
          dict[pos.size()].push_back(cycle(pos, ord));
        } else {
          int pos1 = pos[0];
          int ord1 = ord.back();
          ord.back() = pos[0];
          dict[pos.size()].push_back(cycle(pos, ord));
          pos.clear();
          ord.clear();
          pos.push_back(pos1);
          ord.push_back(ord1);
        }
      }
    }
  }
  int size[10];
  for (int i = 0; i <= 5; i++) size[i] = dict[i].size();
  int common = min(size[2], size[3]);
  int result = size[4] + size[5] + common;
  size[2] -= common;
  size[3] -= common;
  result += size[2] / 2 + size[2] % 2;
  result += (size[3] / 3) * 2 + size[3] % 3;
  std::cout << result << std::endl;
  for (int i = 5; i >= 4; i--) {
    vector<cycle> &vc = dict[i];
    for (int j = 0; j < vc.size(); j++) {
      std::cout << vc[j].ord.size() << std::endl;
      out(vc[j].pos);
      std::cout << std::endl;
      out(vc[j].ord);
      std::cout << std::endl;
    }
  }
  for (int i = 0; i < common; i++) {
    std::cout << 5 << std::endl;
    out(dict[2][i].pos);
    out(dict[3][i].pos);
    std::cout << std::endl;
    out(dict[2][i].ord);
    out(dict[3][i].ord);
    std::cout << std::endl;
  }
  for (int i = common; i < dict[2].size(); i++) {
    if (i + 1 < dict[2].size()) {
      std::cout << 4 << std::endl;
      out(dict[2][i].pos);
      out(dict[2][i + 1].pos);
      std::cout << std::endl;
      out(dict[2][i].ord);
      out(dict[2][i + 1].ord);
      std::cout << std::endl;
      i++;
    } else {
      std::cout << 2 << std::endl;
      out(dict[2][i].pos);
      std::cout << std::endl;
      out(dict[2][i].ord);
      std::cout << std::endl;
    }
  }
  for (int i = common; i < dict[3].size(); i++) {
    if (i + 2 < dict[3].size()) {
      std::cout << 5 << std::endl;
      out(dict[3][i].pos);
      std::cout << dict[3][i + 1].pos[0] + 1 << " " << dict[3][i + 1].pos[1] + 1
                << std::endl;
      out(dict[3][i].ord);
      std::cout << dict[3][i + 1].ord[0] + 1 << " " << dict[3][i + 1].pos[0] + 1
                << std::endl;
      i += 2;
      std::cout << 5 << std::endl;
      out(dict[3][i].pos);
      std::cout << dict[3][i - 1].pos[0] + 1 << " " << dict[3][i - 1].pos[2] + 1
                << std::endl;
      out(dict[3][i].ord);
      std::cout << dict[3][i - 1].ord[1] + 1 << " " << dict[3][i - 1].ord[2] + 1
                << std::endl;
    } else {
      std::cout << 3 << std::endl;
      out(dict[3][i].pos);
      std::cout << std::endl;
      out(dict[3][i].ord);
      std::cout << std::endl;
    }
  }
  return 0;
}
