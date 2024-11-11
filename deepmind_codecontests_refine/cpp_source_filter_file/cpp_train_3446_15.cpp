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
template <typename T, int N>
struct matrix {
  T m[N][N];
  T md;
  matrix(T md, bool unary = false) {
    this->md = md;
    memset(m, 0, sizeof(m));
    if (unary) {
      for (int i = 0; i < N; i++) {
        m[i][i] = 1;
      }
    }
  }
  matrix operator*(const matrix &that) const {
    matrix ret_val(md, false);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          ret_val.m[i][j] += this->m[i][k] * that.m[k][j];
          ret_val.m[i][j] %= md;
        }
      }
    }
    return ret_val;
  }
  vector<T> operator*(const vector<T> &vec) const {
    vector<T> ret_val(vec.size(), 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        ret_val[i] += m[i][j] * vec[j];
        ret_val[i] %= md;
      }
    }
    return ret_val;
  }
  matrix power(int pw) const {
    if (!pw) {
      return matrix(md, true);
    }
    if (pw == 1) {
      return *this;
    }
    matrix ret_val = power(pw >> 1);
    ret_val = ret_val * ret_val;
    if (pw & 1) {
      ret_val = ret_val * (*this);
    }
    return ret_val;
  }
};
void setup(int value, string name) {
  string name_in = name + ".in";
  string name_out = name + ".out";
  freopen(name_in.c_str(), "r", stdin);
  if (value) {
    freopen(name_out.c_str(), "w", stdout);
  }
}
struct R {
  int a;
  int b;
  int i;
  long long tot;
  int pos() const { return a % b; }
  bool operator<(const R &that) const {
    if (this->b != that.b) return this->b < that.b;
    if (this->pos() != that.pos()) return this->pos() < that.pos();
    return this->a < that.a;
  }
};
struct cmp {
  bool operator()(const R &lhs, const R &rhs) const { return lhs.i < rhs.i; }
};
int main() {
  int n;
  std::cin >> n;
  vector<int> vl(n);
  for (int i = 0; i < n; ++i) scanf("%d", &vl[i]);
  int p;
  std::cin >> p;
  vector<R> vr(p);
  for (int i = 0; i < p; ++i) {
    scanf("%d %d", &vr[i].a, &vr[i].b);
    --vr[i].a;
    vr[i].i = i;
    vr[i].tot = 0;
  }
  sort(vr.begin(), vr.end());
  for (int i = 0; i < vr.size(); ++i) {
    int last = i;
    while (last < vr.size() && vr[i].b == vr[last].b &&
           vr[i].pos() == vr[last].pos())
      ++last;
    --last;
    int tmp = last;
    int a = vr[i].a;
    int b = vr[i].b;
    for (int j = ((n - a - 1) / b) * b + a; j >= a; j -= b) {
      vr[last].tot += vl[j];
      while (last != i && vr[last - 1].a == j) {
        --last;
        vr[last].tot = vr[last + 1].tot;
      }
    }
    i = tmp;
  }
  sort(vr.begin(), vr.end(), cmp());
  for (int i = 0; i < p; ++i) std::cout << vr[i].tot << std::endl;
  return 0;
}
