#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1e9 + 5;
const double eps = 1e-7;
const double PI = acos(-1.0);
inline void debug_vi(vector<int> a) {
  for (long long i = (long long)(0); i < (long long)(a.size()); i++)
    cout << a[i] << " ";
}
inline void debug_vll(vector<long long> a) {
  for (long long i = (long long)(0); i < (long long)(a.size()); i++)
    cout << a[i] << " ";
}
inline void print_case(int tn) { cout << "Case #" << tn << ": "; }
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxpq = priority_queue<T>;
const int N = (1 << 24);
long long dp[N + 5] = {0};
int n;
const int NN = 1e4 + 1;
int arr[N];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t clk = clock();
  string s;
  cin >> n;
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    cin >> s;
    arr[i] = 0;
    for (char c : s) {
      arr[i] |= (1 << (c - 'a'));
    }
    dp[arr[i]]++;
  }
  for (long long i = (long long)(0); i < (long long)(24); i++) {
    for (long long mask = (long long)(0); mask < (long long)((1 << 24));
         mask++) {
      if (mask & (1 << i)) {
        dp[mask] += dp[mask ^ (1 << i)];
      }
    }
  }
  long long res = 0;
  for (long long mask = (long long)(0); mask < (long long)((1 << 24)); mask++) {
    int in = (1 << 24) - 1 - mask;
    long long curr = (1 << 24) - dp[in];
    res ^= (curr * curr);
  }
  cout << res;
  cerr << "\n"
       << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC
       << "\n";
  return 0;
}
