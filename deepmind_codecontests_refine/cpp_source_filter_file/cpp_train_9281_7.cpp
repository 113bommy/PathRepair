#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int Chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline int Chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T read() {
  T sum = 0, fl = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
  return sum * fl;
}
inline void proc_status() {
  ifstream t("/proc/self/status");
  cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>())
       << endl;
}
const int Maxn = 5e5 + 100;
const int Mod = 1e9 + 7;
int N, M, A[Maxn], Hash[Maxn];
inline void Add(int &a, int b) {
  if ((a += b) >= Mod) a -= Mod;
}
struct BIT {
  int sum[Maxn << 1];
  inline void add(int first, int val) {
    for (; first <= M; first += first & (-first)) Add(sum[first], val);
  }
  inline int query(int first) {
    int ans = 0;
    for (; first; first -= first & (-first)) Add(ans, sum[first]);
    return ans;
  }
} T[2];
inline void Solve() {
  for (int i = 1; i <= N; ++i) T[1].add(A[i], N - i + 1);
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int sum0 = (long long)T[0].query(A[i]) * (N - i + 1) % Mod;
    int sum1 = (long long)T[1].query(A[i]) * i % Mod;
    Add(ans, (long long)(sum0 + sum1) % Mod * Hash[A[i]] % Mod);
    T[0].add(A[i], i);
    T[1].add(A[i], -(N - i + 1));
  }
  cout << ans << endl;
}
inline void Input() {
  N = read<int>();
  for (int i = 1; i <= N; ++i) A[i] = Hash[i] = read<int>();
  sort(Hash + 1, Hash + N + 1);
  M = unique(Hash + 1, Hash + N + 1) - Hash - 1;
  for (int i = 1; i <= N; ++i)
    A[i] = lower_bound(Hash + 1, Hash + M + 1, A[i]) - Hash;
}
int main() {
  Input();
  Solve();
  return 0;
}
