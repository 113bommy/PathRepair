#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename T>
void printarr(T *A, int n) {
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << "\n";
}
template <typename T>
void arrinit(T *A, int n, T data) {
  for (int i = 0; i < n; i++) {
    A[i] = data;
  }
}
template <typename T>
void takeinput(T *A, int n) {
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
}
template <typename T>
void printcont(T A) {
  for (auto a : A) {
    cout << a << " ";
  }
  cout << "\n";
}
template <typename T>
T binpowmod(T a, T b, T p) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return ((binpowmod(a, b / 2, p) % p) * (binpowmod(a, b / 2, p) % p)) % p;
  return ((a % p) * (binpowmod(a, b - 1, p) % p)) % p;
}
void solve() {
  int n;
  cin >> n;
  long long A[n];
  takeinput(A, n);
  vector<long long> odd_suffix(n, 0);
  if ((n - 1) % 2 == 0) odd_suffix[n - 1] = A[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (i % 2 == 0)
      odd_suffix[i] = odd_suffix[i + 1] + A[i];
    else
      odd_suffix[i] = odd_suffix[i + 1];
  }
  odd_suffix.push_back(0);
  long long dp[n + 2][2];
  for (int i = 0; i < n; i++) {
    dp[i][0] = dp[i][1] = 0LL;
  }
  dp[0][0] = A[0];
  dp[0][1] = 0;
  dp[1][0] = A[0];
  dp[1][1] = A[1];
  long long max_ans = A[0] + odd_suffix[1];
  if (n != 1) max_ans = max(max_ans, A[1] + odd_suffix[2]);
  for (int i = 2; i < n; i++) {
    if (i % 2 == 0) {
      dp[i][0] = dp[i - 1][0] + A[i];
      dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + A[i - 1];
    } else {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + A[i];
    }
    max_ans = max(max_ans, dp[i][1] + odd_suffix[i + 1]);
  }
  cout << max_ans << "\n";
}
int main() {
  auto start = high_resolution_clock::now();
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  return 0;
}
