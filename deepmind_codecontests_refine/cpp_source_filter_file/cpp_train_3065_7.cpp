#include <bits/stdc++.h>
using namespace std;
template <int POS, class TUPLE>
void deploy(std::ostream &os, const TUPLE &tuple) {}
template <int POS, class TUPLE, class H, class... Ts>
void deploy(std::ostream &os, const TUPLE &t) {
  os << (POS == 0 ? "" : ", ") << get<POS>(t);
  deploy<POS + 1, TUPLE, Ts...>(os, t);
}
template <class... Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
  os << "(";
  deploy<0, std::tuple<Ts...>, Ts...>(os, t);
  os << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "" : ", ");
  os << "}";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::set<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "" : ", ");
  os << "}";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::queue<T> &q) {
  auto qq = q;
  os << "{";
  for (; !qq.empty(); qq.pop()) {
    os << qq.front() << (qq.size() != 1 ? ", " : "");
  }
  os << "}";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::priority_queue<T> &q) {
  auto qq = q;
  os << "{";
  for (; !qq.empty(); qq.pop()) {
    os << qq.top() << (qq.size() != 1 ? ", " : "");
  }
  os << "}";
  return os;
}
template <class T, class K>
std::ostream &operator<<(std::ostream &os, std::pair<T, K> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T, class K>
std::ostream &operator<<(std::ostream &os, std::map<T, K> &mp) {
  int remain = mp.size();
  os << "{";
  for (auto e : mp)
    os << "(" << e.first << " -> " << e.second << ")"
       << (--remain == 0 ? "" : ", ");
  os << "}";
  return os;
}
template <class T, class K>
std::ostream &operator<<(std::ostream &os, std::unordered_map<T, K> &mp) {
  int remain = mp.size();
  os << "{";
  for (auto e : mp)
    os << "(" << e.first << " -> " << e.second << ")"
       << (--remain == 0 ? "" : ", ");
  os << "}";
  return os;
}
namespace FastIO {
int32_t readInt32();
int64_t readInt64();
};  // namespace FastIO
inline int32_t FastIO::readInt32() {
  int32_t x = 0;
  char c = getchar();
  bool negative = false;
  for (; c < '0' || '9' < c; c = getchar()) negative |= (c == '-');
  for (; '0' <= c && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  return negative ? -x : x;
}
inline int64_t FastIO::readInt64() {
  int64_t x = 0;
  char c = getchar();
  bool negative = false;
  for (; c < '0' || '9' < c; c = getchar()) negative |= (c == '-');
  for (; '0' <= c && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  return negative ? -x : x;
}
const int MAX = 100500;
vector<int> positions[MAX];
int dat[MAX];
int delim[MAX];
int a[MAX];
int b[MAX];
const int N = 3005;
int dp[N];
int main() {
  using namespace FastIO;
  int n = readInt32();
  int m = readInt32();
  int s = readInt32();
  int e = readInt32();
  for (int32_t i = 0; i < ((int32_t)(n)); ++i) a[i] = readInt32() - 1;
  for (int32_t i = 0; i < ((int32_t)(m)); ++i) b[i] = readInt32() - 1;
  for (int32_t i = 0; i < ((int32_t)(n)); ++i) positions[b[i]].push_back(i);
  for (int32_t i = 0; i < ((int32_t)(MAX - 1)); ++i)
    delim[i + 1] = delim[i] + ((int32_t)((positions[i]).size()));
  for (int32_t i = 0; i < ((int32_t)(MAX)); ++i)
    for (int32_t j = 0; j < ((int32_t)(((int32_t)((positions[i]).size()))));
         ++j)
      dat[delim[i] + j] = positions[i][j];
  int ans = 0;
  for (int32_t i = 0; i < ((int32_t)(N)); ++i) dp[i] = 300500;
  dp[0] = -1;
  for (int32_t a_index = 0; a_index < ((int32_t)(n)); ++a_index) {
    int t = a[a_index];
    int low_base = delim[t];
    int high_base = delim[t + 1];
    for (int dp_index = N - 2; 0 <= dp_index; --dp_index) {
      int low = low_base - 1;
      int high = high_base;
      int pos = dp[dp_index];
      while (low + 1 < high) {
        int mid = (low + high) >> 1;
        if (dat[mid] <= pos)
          low = mid;
        else
          high = mid;
      }
      if (high != high_base && dat[high] < dp[dp_index + 1]) {
        dp[dp_index + 1] = dat[high];
      }
    }
    for (int32_t dp_index = 0; dp_index < ((int32_t)(N)); ++dp_index) {
      int cost = 0;
      cost += dp[dp_index] + 1;
      cost += a_index + 1;
      cost += dp_index * e;
      if (cost <= s) ans = max(ans, dp_index);
    }
  }
  printf("%d\n", ans);
}
