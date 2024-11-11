#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<vector<int> >;
using VS = vector<string>;
using SS = stringstream;
using PII = pair<int, int>;
using VPII = vector<pair<int, int> >;
template <typename T = int>
using VT = vector<T>;
template <typename T = int>
using VVT = vector<vector<T> >;
template <typename T = int>
using LIM = numeric_limits<T>;
template <typename T>
inline istream &operator>>(istream &s, vector<T> &v) {
  for (T &t : v) {
    s >> t;
  }
  return s;
}
template <typename T>
inline ostream &operator<<(ostream &s, const vector<T> &v) {
  for (int i = 0; i < int(v.size()); ++i) {
    s << (" " + !i) << v[i];
  }
  return s;
}
template <typename T>
inline T fromString(const string &s) {
  T res;
  istringstream iss(s);
  iss >> res;
  return res;
}
template <typename T>
inline string toString(const T &a) {
  ostringstream oss;
  oss << a;
  return oss.str();
}
template <typename T>
inline bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
VT<LL> read_norm_str(const int N) {
  VT<LL> res;
  for (int i = (int)(0); i < (int)(N); ++i) {
    int l;
    char c;
    scanf("%d-%c", &l, &c);
    if (!res.empty() && res[res.size() - 2] == c) {
      res.back() += l;
    } else {
      res.push_back(c);
      res.push_back(l);
    }
  }
  return move(res);
}
template <typename Type>
std::vector<int> rollingHash(const std::vector<Type> &S,
                             const std::vector<Type> &T, const int param = 0) {
  const ULL B = vector<ULL>({1000000007, 999999937, 100000007})[param];
  const int len_s = S.size(), len_t = T.size();
  if (len_s < len_t) {
    return {};
  }
  ULL t = 1;
  for (int i = 0; i < len_t; ++i) {
    t *= B;
  }
  ULL hash_t = 0, hash_s = 0;
  for (int i = 0; i < len_t; ++i) {
    hash_t = hash_t * B + T[i];
    hash_s = hash_s * B + S[i];
  }
  std::vector<int> result;
  for (int i = 0; i + len_t <= len_s; ++i) {
    if (hash_t == hash_s) {
      result.push_back(i);
    }
    if (i + len_t < len_s) {
      hash_s = hash_s * B + S[i + len_t] - S[i] * t;
    }
  }
  return result;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  scanf("%d%d", &N, &M);
  const VT<LL> T = read_norm_str(N);
  const VT<LL> S = read_norm_str(M);
  if (((int)(S).size()) == 2) {
    LL res = 0;
    for (int i = (int)(0); i < (int)(((int)(T).size()) / 2); ++i) {
      if (T[i * 2] == S[0]) {
        res += max(0LL, T[i * 2 + 1] - S[1] + 1);
      }
    }
    printf("%I64d\n", res);
    fflush(stdout);
    return 0;
  } else if (((int)(S).size()) == 4) {
    int res = 0;
    for (int i = (int)(0); i < (int)(((int)(T).size()) / 2 - 1); ++i) {
      res += T[i * 2] == S[0] && T[i * 2 + 2] == S[2] && S[1] <= T[i * 2 + 1] &&
             S[3] <= T[i * 2 + 3];
    }
    printf("%d\n", res);
    fflush(stdout);
    return 0;
  } else if (((int)(T).size()) < ((int)(S).size())) {
    puts("0");
    fflush(stdout);
    return 0;
  }
  const VI poss = rollingHash(VT<LL>(begin(T) + 2, end(T) - 2),
                              VT<LL>(begin(S) + 2, end(S) - 2), 1);
  int res = 0;
  for (auto &&pos : poss) {
    const int i = pos + 2;
    res += T[i - 2] == S[0] && S[1] <= T[i - 1] &&
           T[i + ((int)(S).size()) - 4] == S[((int)(S).size()) - 2] &&
           S[((int)(S).size()) - 1] <= T[i + ((int)(S).size()) - 4 + 1];
  }
  printf("%d\n", res);
  fflush(stdout);
  return 0;
}
