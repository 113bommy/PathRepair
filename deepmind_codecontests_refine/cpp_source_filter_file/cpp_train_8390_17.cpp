#include <bits/stdc++.h>
using namespace std;
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr), ios::sync_with_stdio(false),
        cout << fixed << setprecision(20);
  };
} fast_ios_;
template <class T>
auto add = [](T a, T b) -> T { return a + b; };
template <class T>
auto f_max = [](T a, T b) -> T { return max(a, b); };
template <class T>
auto f_min = [](T a, T b) -> T { return min(a, b); };
template <class T>
using V = vector<T>;
using Vl = V<long long int>;
using VVl = V<Vl>;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 != v.size() ? " " : "");
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& in : v) is >> in;
  return is;
}
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int ceil(long long int a, long long int b) { return (a + b - 1) / b; }
long long int digit(long long int a) { return (long long int)log10(a); }
long long int e_dist(pair<long long int, long long int> a,
                     pair<long long int, long long int> b) {
  return abs(a.first - b.first) * abs(a.first - b.first) +
         abs(a.second - b.second) * abs(a.second - b.second);
}
long long int m_dist(pair<long long int, long long int> a,
                     pair<long long int, long long int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
bool check_overflow(long long int a, long long int b, long long int limit) {
  if (b == 0) return false;
  return a > limit / b;
}
void Worshall_Floyd(VVl& g) {
  for (long long int k = (0), k_end_ = (((long long int)(g).size()));
       k < k_end_; ++k)
    for (long long int i = (0), i_end_ = (((long long int)(g).size()));
         i < i_end_; ++i)
      for (long long int j = (0), j_end_ = (((long long int)(g).size()));
           j < j_end_; ++j)
        chmin(g[i][j], g[i][k] + g[k][j]);
}
const long long int MOD1000000007 = 1000000007, MOD998244353 = 998244353,
                    INF = 5e18;
long long int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1},
              dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};
bool YN(bool flag) {
  cout << (flag ? "YES" : "NO") << '\n';
  return flag;
}
bool yn(bool flag) {
  cout << (flag ? "Yes" : "No") << '\n';
  return flag;
}
struct Edge {
  long long int from, to;
  long long int cost;
  Edge() {}
  Edge(long long int u, long long int v, long long int c) {
    cost = c;
    from = u;
    to = v;
  }
  bool operator<(const Edge& e) const { return cost < e.cost; }
};
struct WeightedEdge {
  long long int to;
  long long int cost;
  WeightedEdge(long long int v, long long int c = 1) {
    to = v;
    cost = c;
  }
  bool operator<(const WeightedEdge& e) const { return cost < e.cost; }
};
using WeightedGraph = V<V<WeightedEdge>>;
long long int K;
template <typename T>
struct Matrix_Powers {
 public:
  V<V<T>> Matrix;
  V<T> dp;
  int sz;
  Matrix_Powers(int _sz) : Matrix(_sz, V<T>(_sz, 0)), dp(_sz, 0), sz(_sz){};
  void Matrix_Pow(long long int k) {
    while (k) {
      if (k & 1) Matrix_Mul();
      Update();
      k /= 2;
    }
  }

 private:
  void Matrix_Mul() {
    V<T> res(sz);
    for (long long int i = (0), i_end_ = (sz); i < i_end_; ++i)
      for (long long int j = (0), j_end_ = (sz); j < j_end_; ++j) {
        if (check_overflow(Matrix[i][j], dp[j], K))
          res[i] = K;
        else
          res[i] += Matrix[i][j] * dp[j];
        chmin(res[i], K);
      }
    dp = res;
  }
  void Update() {
    V<V<T>> res(sz, V<T>(sz));
    for (long long int i = (0), i_end_ = (sz); i < i_end_; ++i) {
      for (long long int j = (0), j_end_ = (sz); j < j_end_; ++j) {
        for (long long int k = (0), k_end_ = (sz); k < k_end_; ++k) {
          if (check_overflow(Matrix[i][k], Matrix[k][j], K))
            res[i][j] = K;
          else
            res[i][j] += Matrix[i][k] * Matrix[k][j];
          chmin(res[i][j], K);
        }
      }
    }
    Matrix = res;
  }
};
long long int N;
int main() {
  cin >> N >> K;
  Vl arr(N);
  cin >> arr;
  {
    bool flag = false;
    Vl tmp;
    for (long long int i = (0), i_end_ = (N); i < i_end_; ++i) {
      if (flag || arr[i] != 0) {
        flag = true;
        tmp.push_back(arr[i]);
      }
    }
    swap(tmp, arr);
  }
  N = ((long long int)(arr).size());
  if (N > 10) {
    long long int cnt = 0;
    while (true) {
      for (long long int j = (0), j_end_ = (N); j < j_end_; ++j) {
        if (arr[j] >= K) {
          cout << cnt << '\n';
          return 0;
        }
      }
      Vl sums(N + 1);
      for (long long int j = (0), j_end_ = (N); j < j_end_; ++j) {
        sums[j + 1] = sums[j] + arr[j];
      }
      for (long long int j = (0), j_end_ = (N); j < j_end_; ++j) {
        arr[j] = sums[j + 1];
      }
      cnt++;
    }
  } else {
    auto check = [&](long long int val) {
      Matrix_Powers<long long int> mat(N);
      for (long long int i = (0), i_end_ = (N); i < i_end_; ++i) {
        for (long long int j = (0), j_end_ = (N); j < j_end_; ++j) {
          if (i <= j) mat.Matrix[i][j] = 1;
        }
      }
      for (long long int i = (0), i_end_ = (N); i < i_end_; ++i)
        mat.dp[i] = arr[i];
      mat.Matrix_Pow(val);
      for (long long int i = (0), i_end_ = (N); i < i_end_; ++i) {
        if (mat.dp[i] >= K) return true;
      }
      return false;
    };
    long long int ng = -1, ok = 1e9 + 1;
    while (ok - ng > 1) {
      long long int mid = (ok + ng) / 2;
      if (check(mid))
        ok = mid;
      else
        ng = mid;
    }
    cout << ok << endl;
  }
}
