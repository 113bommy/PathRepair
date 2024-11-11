#include <bits/stdc++.h>
using namespace std;
using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;
using uint8 = int8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;
using float32 = float;
using float64 = double;
template <typename T>
class V : public vector<T> {
 public:
  using vector<T>::vector;
  inline T& operator[](const size_t& index) { return this->at(index); }
  inline const T& operator[](const size_t& index) const {
    return this->at(index);
  }
};
template <typename T, size_t thisSize, size_t... otherSizes>
class A : public array<A<T, otherSizes...>, thisSize> {
 public:
  using array<A<T, otherSizes...>, thisSize>::array;
  inline A<T, otherSizes...>& operator[](const size_t& index) {
    return this->at(index);
  }
  inline const A<T, otherSizes...>& operator[](const size_t& index) const {
    return this->at(index);
  }
};
template <typename T, size_t thisSize>
class A<T, thisSize> : public array<T, thisSize> {
 public:
  using array<T, thisSize>::array;
  inline T& operator[](const size_t& index) { return this->at(index); }
  inline const T& operator[](const size_t& index) const {
    return this->at(index);
  }
};
char buffer[1 << 20];
inline int readInt() {
  int v;
  scanf("%d", &v);
  return v;
}
inline int64 readInt64() {
  int64 v;
  scanf("%" SCNd64, &v);
  return v;
}
inline int64 readUInt64() {
  uint64 v;
  scanf("%" SCNu64, &v);
  return v;
}
inline char readChar() {
  char v;
  scanf("%c", &v);
  return v;
}
inline float64 readFloat64() {
  float64 v;
  scanf("%lf", &v);
  return v;
}
inline string readString() {
  scanf("%s", buffer);
  return string(buffer);
}
inline string readLine() {
  fgets(buffer, sizeof(buffer), stdin);
  return string(buffer);
}
inline void print(const int& v) { printf("%d", v); }
inline void print(const int64& v) { printf("%" PRId64, v); }
inline void print(const uint64& v) { printf("%" PRIu64, v); }
inline void print(const char& v) { printf("%c", v); }
inline void print(const float64& v) { printf("%.20lf", v); }
inline void print(const string& v) { printf("%s", v.c_str()); }
template <typename T1, typename T2>
inline void print(const pair<T1, T2>& v) {
  print('(');
  print(v.first);
  print(", ");
  print(v.second);
  print(')');
}
inline void printLine() { print('\n'); }
template <typename T>
inline void printLine(const T& v) {
  print(v);
  print('\n');
}
template <typename T>
inline void printLine(const V<T>& v) {
  for (int i = 0; i < int(v.size()); i++) {
    if (i) print(' ');
    print(v[i]);
  }
  printLine();
}
template <typename T>
inline void printLine(const V<V<T>>& v) {
  for (const auto& x : v) {
    printLine(x);
  }
}
template <typename T>
inline void logln_(const T& v) {
  print("log: ");
  printLine(v);
}
template <typename T>
inline void logln_(const V<T>& v) {
  print("log: ");
  printLine(v);
}
template <typename T>
inline void logln_(const V<V<T>>& v) {
  for (const auto& x : v) {
    logln_(x);
  }
}
void solve();
int main() {
  srand(time(nullptr));
  solve();
  return 0;
}
V<int> stops;
int can(float64 alpha) {
  float64 have = 0;
  int pos = 0;
  for (int i = 0; i < int(stops.size()); i++) {
    float64 d = stops[i] - pos;
    if (have + alpha < d * 10.0) {
      return -1;
    }
    if (have + alpha >= (d + 1.0) * 10.0) {
      return 1;
    }
    pos = stops[i];
    have += alpha;
    have -= d * 10.0;
  }
  return 0;
}
int ans(float64 alpha) {
  float64 have = 0;
  int pos = 0;
  for (int i = 0; i < int(stops.size()); i++) {
    float64 d = stops[i] - pos;
    pos = stops[i];
    have += alpha;
    have -= d * 10.0;
  }
  return pos + int((have + alpha) / 10.0);
}
void solve() {
  int n = readInt();
  stops.resize(n);
  for (int i = 0; i < n; i++) {
    stops[i] = readInt();
  }
  float64 ansL;
  float64 lo = 10.0;
  float64 hi = float64(1 << 20);
  for (int i = 0; i < 300; i++) {
    float64 m = lo + (hi - lo) / 2.0;
    if (can(m) == -1) {
      lo = m;
    } else {
      hi = m;
    }
  }
  ansL = lo;
  float64 ansR;
  lo = 10.0;
  hi = float64(1 << 20);
  for (int i = 0; i < 300; i++) {
    float64 m = lo + (hi - lo) / 2.0;
    if (can(m) <= 0) {
      lo = m;
    } else {
      hi = m;
    }
  }
  ansR = lo;
  static_cast<void>(0);
  static_cast<void>(0);
  static_cast<void>(0);
  static_cast<void>(0);
  int ans1 = ans(ansL + 1e-9);
  int ans2 = ans(ansR - 1e-9);
  if (ans1 == ans2) {
    printLine("unique");
    printLine(ans1);
  } else {
    printLine("not unique");
  }
}
