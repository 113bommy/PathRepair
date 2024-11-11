#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int>& i, const pair<int, int>& j) {
  if (i.second == j.second) return i.first > j.first;
  return i.second > j.second;
}
int ncr(int n, int k) {
  if (n < k) return 0;
  int C[n + 1][k + 1];
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
    }
  }
  return C[n][k];
}
long long int modpowIter(long long int a, long long int b, long long int c) {
  int ans = 1;
  while (b != 0) {
    if (b % 2 == 1) ans = (ans * a) % c;
    a = (a * a) % c;
    b /= 2;
  }
  return ans;
}
string intobin(int n) {
  string s = "";
  if (n == 0) s = "0";
  while (n) {
    if (n % 2)
      s = "1" + s;
    else
      s = "0" + s;
    n /= 2;
  }
  return s;
}
int bintoin(string s) {
  long long int n = 0;
  vector<long long int> v;
  v.push_back(1);
  for (long long int i = 0; i < 400; i++) {
    v.push_back((v[v.size() - 1] * 2) % 1000003);
  }
  for (int i = s.length() - 1; i > -1; i--) {
    n = (n + (s[i] - '0') * v[s.length() - i - 1]) % 1000003;
  }
  return n;
}
long long int nc2(long long int n, long long int k) {
  if (n < k) return 0;
  return (n * (n - 1)) / 2;
}
bool prime[1000001];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  cout << n / 2 << "\n";
  return 0;
}
