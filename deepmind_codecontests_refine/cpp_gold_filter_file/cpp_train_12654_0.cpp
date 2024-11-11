#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
inline int Pow(int b, int p) {
  if (!p) return 1;
  int sq = Pow(b, p >> 1);
  sq *= sq;
  if (p & 1) sq *= b;
  return sq;
}
inline int gcd(int a, int b) {
  if (!a) return b;
  return gcd(b % a, a);
}
inline string toString(int x) {
  stringstream SS;
  SS << x;
  return SS.str();
}
int n;
long long arr[505][505];
bool check(long long row_sum) {
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      sum += arr[i][j];
    }
    if (sum != row_sum) return 0;
  }
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      sum += arr[j][i];
    }
    if (sum != row_sum) return 0;
  }
  long long rd_sum = 0;
  for (int i = 0; i < n; i++) rd_sum += arr[i][i];
  if (rd_sum != row_sum) return 0;
  long long ld_sum = 0;
  for (int i = 0; i < n; i++) ld_sum += arr[i][n - 1 - i];
  if (ld_sum != row_sum) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> n) {
    int r = 0, c = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
        if (!arr[i][j]) {
          r = i;
          c = j;
        }
      }
    }
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    int temp_r = (r + 1) % n;
    long long row_sum = 0;
    for (int j = 0; j < n; j++) row_sum += arr[temp_r][j];
    long long row_empty_sum = 0;
    for (int j = 0; j < n; j++) row_empty_sum += arr[r][j];
    long long rem = row_sum - row_empty_sum;
    if (rem > 0) {
      arr[r][c] = rem;
      if (check(row_sum))
        cout << rem << endl;
      else
        cout << -1 << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
