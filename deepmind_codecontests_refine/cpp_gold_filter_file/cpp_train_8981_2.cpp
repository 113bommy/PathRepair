#include <bits/stdc++.h>
using namespace std;
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }
  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod()) value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0) value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) *
                                     rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }
  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) {
    return v;
  }
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};
template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}
template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}
template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
template <typename T>
struct Matrix {
  vector<vector<T>> matrix;
  int size{2};
  Matrix() {
    matrix = {{0, 0}, {0, 0}};
    size = 2;
  }
  explicit Matrix(int n) {
    matrix.resize(n);
    for (int i = 0; i < n; ++i) matrix[i].resize(n);
    size = n;
  }
  Matrix(const Matrix& other) : size{other.size} {
    matrix.resize(size);
    for (int i = 0; i < size; ++i) matrix[i].resize(size);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) matrix[i][j] = other.matrix[i][j];
  }
  Matrix operator*(const Matrix& other) {
    Matrix new_matrix(size);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        for (int k = 0; k < size; ++k)
          new_matrix.matrix[i][k] += matrix[i][j] * other.matrix[j][k];
    return new_matrix;
  }
  Matrix& operator+=(const Matrix& other) {
    assert(size == other.size);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) matrix[i][j] += other.matrix[i][j];
    return *this;
  }
  Matrix& operator-=(const Matrix& other) {
    assert(size == other.size);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) matrix[i][j] -= other.matrix[i][j];
    return *this;
  }
  Matrix operator+(const Matrix& other) const {
    assert(size == other.size);
    Matrix copy{*this};
    copy += other;
    return copy;
  }
  Matrix operator-(const Matrix& other) const {
    assert(size == other.size);
    Matrix copy{*this};
    copy -= other;
    return copy;
  }
};
template <typename T>
ostream& operator<<(ostream& stream, const Matrix<T>& m) {
  int n = m.size;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) stream << m.matrix[i][j] << " \n"[j + 1 == n];
  return stream;
}
template <typename T, typename A>
Matrix<T> matrix_power(Matrix<T> m, A b, int n) {
  Matrix<T> result(n);
  for (int i = 0; i < n; ++i) result.matrix[i][i] = 1;
  while (b) {
    if (b % 2) result = result * m;
    m = m * m;
    b /= 2;
  }
  return result;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M));
    bool is_n = true, z = false;
    int s = 0;
    int neg = 0;
    int mx = -1e9;
    int mn = 1e9;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> a[i][j];
        if (a[i][j] > 0) {
          mn = min(mn, a[i][j]);
          s += a[i][j];
        }
        if (a[i][j] < 0) {
          mx = max(mx, a[i][j]);
          s += -a[i][j];
          ++neg;
          is_n = true;
        }
        if (a[i][j] == 0) {
          z = true;
        }
      }
    }
    if (!is_n || z || neg % 2 == 0) {
      cout << s << '\n';
      continue;
    }
    mn = 0 - mn;
    mx = max(mx, mn);
    cout << s + mx + mx << '\n';
  }
  return 0;
}
