#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
namespace Xrocks {}
using namespace Xrocks;
namespace Xrocks {
class in {
} user_input;
class out {
} output;
in& operator>>(in& X, int& Y) {
  scanf("%d", &Y);
  return X;
}
in& operator>>(in& X, char* Y) {
  scanf("%s", Y);
  return X;
}
in& operator>>(in& X, float& Y) {
  scanf("%f", &Y);
  return X;
}
in& operator>>(in& X, double& Y) {
  scanf("%lf", &Y);
  return X;
}
in& operator>>(in& X, char& C) {
  scanf("%c", &C);
  return X;
}
in& operator>>(in& X, string& Y) {
  cin >> Y;
  return X;
}
in& operator>>(in& X, long long& Y) {
  scanf("%lld", &Y);
  return X;
}
template <typename T>
in& operator>>(in& X, vector<T>& Y) {
  for (auto& x : Y) user_input >> x;
  return X;
}
template <typename T>
out& operator<<(out& X, const T& Y) {
  cout << Y;
  return X;
}
template <typename T>
out& operator<<(out& X, vector<T>& Y) {
  for (auto& x : Y) output << x << " ";
  return X;
}
out& operator<<(out& X, const int& Y) {
  printf("%d", Y);
  return X;
}
out& operator<<(out& X, const char& C) {
  printf("%c", C);
  return X;
}
out& operator<<(out& X, const string& Y) {
  printf("%s", Y.c_str());
  return X;
}
out& operator<<(out& X, const long long& Y) {
  printf("%lld", Y);
  return X;
}
out& operator<<(out& X, const float& Y) {
  printf("%f", Y);
  return X;
}
out& operator<<(out& X, const double& Y) {
  printf("%lf", Y);
  return X;
}
out& operator<<(out& X, const char Y[]) {
  printf("%s", Y);
  return X;
}
template <typename T>
T max(T A) {
  return A;
}
template <typename T, typename... args>
T max(T A, T B, args... S) {
  return max(A > B ? A : B, S...);
}
template <typename T>
T min(T A) {
  return A;
}
template <typename T, typename... args>
T min(T A, T B, args... S) {
  return min(A < B ? A : B, S...);
}
template <typename T>
void vectorize(int y, vector<T>& A) {
  A.resize(y);
}
template <typename T, typename... args>
void vectorize(int y, vector<T>& A, args&&... S) {
  A.resize(y);
  vectorize(y, S...);
}
long long fast(long long a, long long b, long long pr) {
  if (b == 0) return 1 % pr;
  long long ans = 1 % pr;
  while (b) {
    if (b & 1) ans = (ans * a) % pr;
    b >>= 1;
    a = (a * a) % pr;
  }
  return ans;
}
int readInt() {
  int n = 0;
  int ch = getchar_unlocked();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar_unlocked();
  }
  while (ch >= '0' && ch <= '9')
    n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
  n = n * sign;
  return n;
}
long long readLong() {
  long long n = 0;
  int ch = getchar_unlocked();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar_unlocked();
  }
  while (ch >= '0' && ch <= '9')
    n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
  n = n * sign;
  return n;
}
long long readBin() {
  long long n = 0;
  int ch = getchar_unlocked();
  int sign = 1;
  while (ch < '0' || ch > '1') {
    if (ch == '-') sign = -1;
    ch = getchar_unlocked();
  }
  while (ch >= '0' && ch <= '1')
    n = (n << 1) + (ch - '0'), ch = getchar_unlocked();
  return n;
}
long long inv_(long long val,
               long long pr = static_cast<long long>(1000000007)) {
  return fast(val, pr - 2, pr);
}
}  // namespace Xrocks
int capK, capK2;
class seg_tree {
  vector<int> tree;
  vector<map<int, int>> tree2;
  int n;
  inline int get_size(int R) {
    R--;
    int Z = 1;
    while (R) {
      Z <<= 1;
      R >>= 1;
    }
    return Z * 2;
  }

 public:
  void construct(int s) {
    tree2.resize(get_size(s));
    n = s - 1;
  }
  int find_max(int l, int r, int K) { return find_max2(l, r, K, 0, n, 1); }
  int find_max2(int l, int r, int K, int L, int R, int curr) {
    if (r < L || l > R || tree2[curr].lower_bound(K) == tree2[curr].end())
      return 0;
    if (L >= l && R <= r) {
      int ans = 0;
      auto i = tree2[curr].lower_bound(K);
      while (i != tree2[curr].end() && i->first <= K + capK2) {
        ans += i->second;
        ++i;
      }
      return ans;
    }
    int c = curr;
    return (find_max2(l, r, K, L, (L + R) / 2, 2 * curr) +
            find_max2(l, r, K, (L + R) / 2 + 1, R, 2 * curr + 1));
  }
  void update(int pos, int val) { update(pos, val, 1, 0, n); }
  void update(int pos, int val, int c, int L, int R) {
    int curr = c;
    if (pos < L || pos > R) return;
    if (L == R) {
      tree2[c][val]++;
      return;
    }
    update(pos, val, curr << 1, L, (L + R) >> 1);
    update(pos, val, (curr << 1) + 1, ((L + R) >> 1) + 1, R);
    tree2[c][val]++;
    return;
  }
  void update2(int pos, int val) { update2(pos, val, 1, 0, n); }
  void update2(int pos, int val, int c, int L, int R) {
    int curr = c;
    if (pos < L || pos > R) return;
    if (L == R) {
      tree2[c][val]--;
      return;
    }
    update2(pos, val, curr << 1, L, (L + R) >> 1);
    update2(pos, val, (curr << 1) + 1, ((L + R) >> 1) + 1, R);
    tree2[c][val]--;
    return;
  }
};
class solve {
  long long n, k;
  vector<int> v, r, q, invw;
  seg_tree St;

 public:
  solve() {
    user_input >> n >> capK;
    capK2 = 2 * capK;
    v.resize(n);
    r.resize(n);
    q.resize(n);
    invw.resize(n);
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
      idx[i] = i;
      user_input >> v[i] >> r[i] >> q[i];
    }
    sort(idx.begin(), idx.end(),
         [&](const int& a, const int& b) { return v[a] < v[b]; });
    vector<int> v2(1);
    invw[idx[0]] = 0;
    v2[0] = v[idx[0]];
    int prev = v2[0];
    for (int i = 1; i < n; i++) {
      if (v[idx[i - 1]] == v[idx[i]]) {
        invw[idx[i]] = invw[idx[i - 1]];
      } else {
        invw[idx[i]] = invw[idx[i - 1]] + 1;
      }
      if (prev != v[idx[i]]) v2.push_back(v[idx[i]]);
      prev = v[idx[i]];
    }
    St.construct(v2.size());
    set<pair<int, int>> S;
    long long a = 0;
    for (int i = 0; i < n; i++) {
      int c = idx[i];
      while (!S.empty() && S.begin()->first < v[c]) {
        St.update2(invw[S.begin()->second], q[S.begin()->second]);
        S.erase(S.begin());
      }
      int l2, r2;
      l2 = lower_bound(v2.begin(), v2.end(), v[c] - r[c]) - v2.begin();
      r2 = upper_bound(v2.begin(), v2.end(), v[c] + r[c]) - v2.begin();
      --r2;
      a += St.find_max(l2, r2, q[c] - capK);
      St.update(invw[c], q[c]);
      S.insert({v[c] + r[c], i});
    }
    output << a;
  }
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
};
int32_t main() {
  int t = 1, i = 1;
  if (0 || 0) scanf("%d", &t);
  while (t--) {
    if (0) printf("Case #%d: ", i++);
    new solve;
  }
  output << "\n";
  return 0;
}
