#include <bits/stdc++.h>
int dx[] = {0, 0, 1, -1, 2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 2, 2, -2, -2};
using namespace std;
long long int mem[1010][1110];
long long int com(long long int n, long long int k) {
  if (k > n) {
    return 0;
  }
  if (k == n || k == 0) {
    return 1;
  }
  if (mem[n][k] > 0) {
    return mem[n][k];
  }
  return mem[n][k] =
             ((com(n - 1, k) % 1000000007) + com(n - 1, k - 1) % 1000000007) %
             1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int tcase = 1;
  for (long long int test = 1; test <= tcase; test++) {
    long long int num, m;
    cin >> num >> m;
    long long int ans = 0;
    for (long long int i = 1; i <= num; i++) {
      long long int ar_a_n = (i - 1) + 1;
      long long int ar_b_n = (num - i) + 1;
      long long int n_a = (ar_a_n - 1) + (m - 1);
      long long int k_a = ar_a_n - 1;
      long long int ans_a = com(n_a, k_a);
      long long int n_b = (ar_b_n - 1) + m;
      long long int k_b = ar_b_n - 1;
      long long int ans_b = com(n_b, k_b);
      long long int tm_ans =
          ((ans_b % 1000000007) * (ans_a % 1000000007)) % 1000000007;
      ans = ((ans % 1000000007) + (tm_ans % 1000000007)) % 1000000007;
    }
    cout << ans << "\n";
  }
}
