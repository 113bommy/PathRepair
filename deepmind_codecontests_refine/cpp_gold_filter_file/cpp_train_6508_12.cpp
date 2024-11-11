#include <bits/stdc++.h>
const int MAX = 1e5 + 11;
using namespace std;
const int MOD = (const int)(1e9 + 7);
const int INF = (const int)1e9;
template <typename T>
struct Matrix {
  static Matrix Identity(std::size_t N, std::size_t M,
                         const std::size_t mod = (const size_t)(1e9 + 7)) {
    auto result = Matrix(N, M, mod);
    for (std::int32_t i = 0; i < N; ++i) {
      result.data_[i * (M + 1)] = 1;
    }
    return result;
  }
  Matrix(std::size_t N, std::size_t M,
         const std::size_t mod = (const size_t)(1e9 + 7)) {
    assert(mod != 0);
    N_ = N;
    M_ = M;
    mod_ = mod;
    data_ = static_cast<T *>(calloc(N_ * M_, sizeof(T)));
  }
  Matrix(const Matrix &rhs) {
    N_ = rhs.N_;
    M_ = rhs.M_;
    mod_ = rhs.mod_;
    data_ = static_cast<T *>(malloc(N_ * M_ * sizeof(T)));
    memmove(data_, rhs.data_, N_ * M_ * sizeof(T));
  }
  Matrix &operator=(const Matrix &rhs) {
    assert(N_ == rhs.N_ && M_ == rhs.M_);
    N_ = rhs.N_;
    M_ = rhs.M_;
    mod_ = rhs.mod_;
    data_ = static_cast<T *>(malloc(N_ * M_ * sizeof(T)));
    memmove(data_, rhs.data_, N_ * M_ * sizeof(T));
    return *this;
  }
  virtual ~Matrix() { free(data_); }
  void Power(const std::int32_t power) {
    assert(N_ == M_);
    Matrix res = Matrix::Identity(N_, M_, mod_);
    ;
    Matrix q = *this;
    std::int32_t x = power;
    while (x > 0) {
      if (x & 1) {
        res *= q;
      }
      q *= q;
      x >>= 1;
    }
    *this = res;
  }
  void Multiply(const Matrix &rhs) {
    assert(M_ == rhs.N_);
    Matrix result(N_, rhs.M_, mod_);
    for (std::int32_t i = 0; i < N_; ++i) {
      for (std::int32_t j = 0; j < M_; ++j) {
        for (std::int32_t k = 0; k < M_; ++k) {
          auto &a = result.data_[i * M_ + j];
          const auto &b = data_[i * M_ + k];
          const auto &c = rhs.data_[k * rhs.M_ + j];
          a = static_cast<T>((1LL * a + 1LL * b * c) % mod_);
        }
      }
    }
    *this = result;
  }
  void Add(const Matrix &rhs) {
    assert(N_ == rhs.N_ && M_ == rhs.M_);
    for (std::int32_t i = 0; i < N_; ++i) {
      for (std::int32_t j = 0; j < M_; ++j) {
        auto &a = data_[i * M_ + j];
        const auto &b = rhs.data_[i * M_ + j];
        a = static_cast<T>((1LL * a + b) % mod_);
      }
    }
  }
  void Subtract(const Matrix &rhs) {
    assert(N_ == rhs.N_ && M_ == rhs.M_);
    for (std::int32_t i = 0; i < N_; ++i) {
      for (std::int32_t j = 0; j < M_; ++j) {
        auto &a = data_[i * M_ + j];
        const auto &b = rhs.data_[i * M_ + j];
        a = static_cast<T>((1LL * a - b) % mod_);
      }
    }
  }
  Matrix operator*(const Matrix &rhs) const {
    Matrix result = *this;
    result.Multiply(rhs);
    return result;
  }
  Matrix operator+(const Matrix &rhs) const {
    Matrix result = *this;
    result.Add(rhs);
    return result;
  }
  Matrix operator-(const Matrix &rhs) const {
    Matrix result = *this;
    result.Subtract(rhs);
    return result;
  }
  Matrix &operator*=(const Matrix &rhs) {
    Multiply(rhs);
    return *this;
  }
  Matrix &operator+=(const Matrix &rhs) {
    Add(rhs);
    return *this;
  }
  Matrix &operator-=(const Matrix &rhs) {
    Subtract(rhs);
    return *this;
  }
  class Proxy {
   public:
    Proxy(T *array) : sub_data(array) {}
    T &operator[](std::int32_t index) { return sub_data[index]; }

   private:
    T *sub_data;
  };
  Proxy operator[](std::int32_t index) const {
    return Proxy(&data_[index * M_]);
  }
  void Print() const {
    for (std::int32_t i = 0; i < N_; ++i) {
      for (std::int32_t j = 0; j < M_; ++j) {
        std::cout << this->operator[](i)[j] << " ";
      }
      std::cout << "\n";
    }
  }

 private:
  T *data_;
  std::size_t N_, M_, mod_;
};
int N, b, k, x;
int A[MAX];
static void solve(int test) {
  scanf("%d %d %d %d", &N, &b, &k, &x);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  Matrix<std::int32_t> w(x, x), e(x, x);
  for (int i = 0; i < x; ++i) {
    w[i][(i * 10) % x] = 1;
  }
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < N; ++j) {
      e[i][(i + A[j]) % x]++;
    }
  }
  auto m = (w * e);
  m.Power(b);
  printf("%d", m[0][k]);
}
int main() {
  ios_base::sync_with_stdio(0);
  solve(0);
  return 0;
}
