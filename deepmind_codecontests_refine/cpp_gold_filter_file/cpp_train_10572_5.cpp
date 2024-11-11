#include <bits/stdc++.h>
using namespace std;
int lg(long long n) {
  assert(n > 0);
  int ans = -1;
  while (n) {
    ans++;
    n >>= 1;
  }
  return ans;
}
template <typename T, int NDIMS>
struct tensor_view {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

 protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  T* data;
  tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_,
              T* data_)
      : shape(shape_), strides(strides_), data(data_) {}

 public:
  tensor_view() : shape{0}, strides{0}, data(nullptr) {}

 protected:
  int flatten_index(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      res += idx[i] * strides[i];
    }
    return res;
  }
  int flatten_index_checked(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      assert(0 <= idx[i] && idx[i] < shape[i]);
      res += idx[i] * strides[i];
    }
    return res;
  }

 public:
  T& operator[](std::array<int, NDIMS> idx) const {
    return data[flatten_index(idx)];
  }
  T& at(std::array<int, NDIMS> idx) const {
    return data[flatten_index_checked(idx)];
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](
      int idx) const {
    std::array<int, NDIMS - 1> nshape;
    std::copy(shape.begin() + 1, shape.end(), nshape.begin());
    std::array<int, NDIMS - 1> nstrides;
    std::copy(strides.begin() + 1, strides.end(), nstrides.begin());
    T* ndata = data + (strides[0] * idx);
    return tensor_view<T, NDIMS - 1>(nshape, nstrides, ndata);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(
      int idx) const {
    assert(0 <= idx && idx < shape[0]);
    return operator[](idx);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), T&>::type operator*() const {
    return *data;
  }
  template <typename U, int D>
  friend struct tensor_view;
  template <typename U, int D>
  friend struct tensor;
};
template <typename T, int NDIMS>
struct tensor {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

 protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  int len;
  T* data;

 public:
  tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}
  explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
    shape = shape_;
    strides[NDIMS - 1] = 1;
    for (int i = NDIMS - 1; i > 0; i--) {
      strides[i - 1] = strides[i] * shape[i];
    }
    len = strides[0] * shape[0];
    data = new T[len];
    std::fill(data, data + len, t);
  }
  tensor(const tensor& o)
      : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
    for (int i = 0; i < len; i++) {
      data[i] = o.data[i];
    }
  }
  tensor& operator=(tensor&& o) noexcept {
    using std::swap;
    swap(shape, o.shape);
    swap(strides, o.strides);
    swap(len, o.len);
    swap(data, o.data);
    return *this;
  }
  tensor(tensor&& o) : tensor() { *this = std::move(o); }
  tensor& operator=(const tensor& o) { return *this = tensor(o); }
  ~tensor() { delete[] data; }
  using view_t = tensor_view<T, NDIMS>;
  view_t view() { return tensor_view<T, NDIMS>(shape, strides, data); }
  operator view_t() { return view(); }
  using const_view_t = tensor_view<const T, NDIMS>;
  const_view_t view() const {
    return tensor_view<const T, NDIMS>(shape, strides, data);
  }
  operator const_view_t() const { return view(); }
  T& operator[](std::array<int, NDIMS> idx) { return view()[idx]; }
  T& at(std::array<int, NDIMS> idx) { return view().at(idx); }
  const T& operator[](std::array<int, NDIMS> idx) const { return view()[idx]; }
  const T& at(std::array<int, NDIMS> idx) const { return view().at(idx); }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](
      int idx) {
    return view()[idx];
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(
      int idx) {
    return view().at(idx);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type
  operator[](int idx) const {
    return view()[idx];
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type at(
      int idx) const {
    return view().at(idx);
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), T&>::type operator*() {
    return *view();
  }
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), const T&>::type operator*() const {
    return *view();
  }
};
struct RMQ2D {
  int n, m;
  vector<vector<int>> val;
  tensor<int, 4> table;
  using state = array<int, 4>;
  RMQ2D(const vector<vector<int>>& vvi) {
    n = (int)vvi.size();
    m = (int)vvi[0].size();
    val = vvi;
    table = tensor<int, 4>({1 + lg(n), n, 1 + lg(m), m}, 0);
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        table[state{0, row, 0, col}] = vvi[row][col];
      }
      for (int j = 1; j <= lg(m); j++) {
        for (int i = 0; i + (1 << j) - 1 < m; i++) {
          table[state{0, row, j, i}] =
              max(table[state{0, row, j - 1, i}],
                  table[state{0, row, j - 1, i + (1 << (j - 1))}]);
        }
      }
    }
    for (int jr = 1; jr <= lg(n); jr++) {
      for (int row = 0; row + (1 << jr) - 1 < n; row++) {
        for (int jc = 0; jc <= lg(m); jc++) {
          for (int col = 0; col + (1 << jc) - 1 < m; col++) {
            table[state{jr, row, jc, col}] =
                max(table[state{jr - 1, row, jc, col}],
                    table[state{jr - 1, row + (1 << (jr - 1)), jc, col}]);
          }
        }
      }
    }
  }
  int query(int x1, int y1, int x2, int y2) {
    int kx = lg(x2 - x1 + 1), ky = lg(y2 - y1 + 1);
    return max({table[state{kx, x1, ky, y1}],
                table[state{kx, x2 - (1 << kx) + 1, ky, y1}],
                table[state{kx, x1, ky, y2 - (1 << ky) + 1}],
                table[state{kx, x2 - (1 << kx) + 1, ky, y2 - (1 << ky) + 1}]});
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = grid[i][j];
      else {
        if (grid[i][j] == 1)
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        else {
          dp[i][j] = 0;
        }
      }
    }
  }
  RMQ2D rmq(dp);
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1);
    while (l < r) {
      int m = ((l + r) >> 1) + 1;
      if (rmq.query(x1 + m - 1, y1 + m - 1, x2, y2) >= m) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    cout << l << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
