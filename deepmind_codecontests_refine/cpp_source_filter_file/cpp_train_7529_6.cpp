#include <bits/stdc++.h>
using namespace std;
const int fx[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int fxx[9][2] = {{0, 0}, {0, 1},  {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void subsequences(long long ar[], long long n);
long long apow(long long a, long long b);
long long bpow(long long a, long long b, long long mod);
long long __gcd(long long a, long long b);
bool dio(long long a, long long b, long long c);
bool palindrome(string s);
void sieve();
long long binarySearch(vector<long long> vec, long long n, long long x);
long long kadane(vector<long long> vec, long long n);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long map[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j) {
        sum += map[i][j];
      }
      if (i + j == n) {
        sum += map[i][j];
      }
      if (i == n / 2) {
        sum += map[i][j];
      }
      if (j == n / 2) {
        sum += map[i][j];
      }
    }
  }
  cout << sum - (3 * map[n / 2][n / 2]) + 1;
}
