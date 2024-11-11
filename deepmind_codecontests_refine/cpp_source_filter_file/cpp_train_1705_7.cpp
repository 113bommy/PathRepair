#include <bits/stdc++.h>
using namespace std;
inline long long int gcd(long long int a, long long int b) {
  while (b) {
    b = a % b;
    swap(a, b);
  }
  return a;
}
inline long long int powmod(long long int base, long long int exponent,
                            long long int mod = (1e9 + 7)) {
  long long int ans = 1;
  while (exponent) {
    if (exponent & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    exponent >>= 1;
  }
  return ans;
}
inline vector<int> Siv(int n) {
  int i, p;
  vector<bool> prime;
  vector<int> pr;
  for (i = 0; i <= n; i++) prime.push_back(true);
  for (p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      pr.push_back(p);
      for (i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }
  for (i = p; i <= n; i++) {
    if (prime[i] == true) {
      pr.push_back(i);
    }
  }
  return pr;
}
inline int factors(int n, vector<int> pr, int *pt, int max1) {
  int count = 0, tot = 0, temp = n, num = 0, flag;
  for (int x = 0; x < pr.size(); x++) {
    count = 0, flag = 0;
    while (temp % pr[x] == 0) {
      count++;
      temp = temp / pr[x];
      flag = 1;
    }
    tot = tot + count;
    if (temp == 1) break;
  }
  if (temp != 1) return tot + 1;
  return tot;
}
inline long long int ncr(long long int n, long long int r) {
  r = min(r, n - r);
  long long int arr[r + 1];
  memset(arr, 0, sizeof(arr));
  arr[0] = 1;
  long long int i, j;
  for (i = 1; i < n + 1; ++i)
    for (j = min(i, r); j > 0; --j) arr[j] = (arr[j] + arr[j - 1]) % 1000000007;
  return arr[r];
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, a, b, c, q, h, i, j, k, n, n1, n2, n3, min1, min2, max1,
      max2, lsb, sum, tot, rem, ans, prod, diff, count, flag, temp, temp1,
      temp2;
  long long int mod = 1000000007, inf = INT_MAX, pr = 998244353;
  string s;
  for (t = 1; t--; cout << "\n") {
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << a + 1 << "\n";
    for (i = 0; i < a + 1; ++i) {
      cout << i << " " << i << "\n";
    }
  }
}
