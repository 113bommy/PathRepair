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
inline int numbits(T n) {
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
  bool *p = new bool[end + 1];
  init_array<bool>(p, end + 1, 0);
  p[1] = 1;
  for (int i = 2; i <= end; i++) {
    if (!p[i]) {
      if (i >= start) vi.push_back(i);
      for (int j = 2 * i; j <= end; j += i) p[j] = 1;
    }
  }
  delete[] p;
}
bool dfs(int current, int final, int total, vector<int> &visited,
         vector<vector<bool> > &edges, bool flow) {
  if (current == final) return true;
  if (visited[current]) return false;
  visited[current] = true;
  for (int i = 0; i < total; i++)
    if (edges[current][i] && dfs(i, final, total, visited, edges, flow)) {
      if (flow) {
        edges[current][i] = false;
        edges[i][current] = true;
      }
      return true;
    }
  return false;
}
int flow(int in, int out, int total, vector<vector<bool> > &edges) {
  int result = 0;
  for (vector<int> visited(total, 0); dfs(in, out, total, visited, edges, true);
       ++result)
    visited = vector<int>(total, 0);
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
    if (!pw) return matrix(md, true);
    if (pw == 1) return *this;
    matrix ret_val = power(pw >> 1);
    ret_val = ret_val * ret_val;
    if (pw & 1) ret_val = ret_val * (*this);
    return ret_val;
  }
};
void setup(int value, string name) {
  string name_in = name + ".in";
  string name_out = name + ".out";
  freopen(name_in.c_str(), "r", stdin);
  if (value) freopen(name_out.c_str(), "w", stdout);
}
int C[5001];
int dp[5001][5001];
void eval_c(long long m, long long p) {
  vector<long long> vi;
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= min(5000, (int)m); ++i) {
    vi.push_back(m - i + 1);
    long long val = i;
    for (int j = 0; val != 1; ++j) {
      long long g = gcd(vi[j], val);
      vi[j] /= g;
      val /= g;
    }
    long long res = 1;
    for (int j = 0; j < vi.size(); ++j) {
      res *= vi[j];
      res %= p;
    }
    C[i] = (int)res;
  }
}
void eval_dp(long long p) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= 5000; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[j][i] = (int)(((long long)dp[j - 1][i - 1] * (long long)j +
                        (long long)dp[j][i - 1] * (long long)(j - 1)) %
                       p);
    }
  }
}
void run() {
  int n, m, p;
  std::cin >> n >> m >> p;
  eval_c(m, p);
  eval_dp(p);
  vector<int> vi1, vi2;
  vi1.reserve(8000), vi2.reserve(8000);
  vi1.push_back(1);
  for (int i = 0; i < n; ++i) {
    if (vi1.capacity() != 8000) std::cout << vi1.capacity();
    int len;
    scanf("%d", &len);
    long long total = accumulate(vi1.begin(), vi1.end(), 0LL) % p;
    for (int j = 0; j <= len; ++j) {
      long long cc1 = C[j];
      long long cc2 = dp[j][len];
      long long prev = (j < vi1.size()) ? vi1[j] : 0;
      vi2.push_back((int)((((cc1 * cc2) % p) * total) % p));
      vi2[j] = (p - (int)((cc2 * prev) % p) + vi2[j]) % p;
    }
    vi1.swap(vi2);
    vi2.resize(0);
  }
  std::cout << (accumulate(vi1.begin(), vi1.end(), 0LL) % p) << std::endl;
}
int main() {
  run();
  return 0;
}
