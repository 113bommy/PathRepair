#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
bool isPerfectSquare(long long n) {
  long long sr = sqrt(n);
  if (sr * sr == n)
    return true;
  else
    return false;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
void SieveOfEratosthenes(vector<bool>& mem) {
  long long n = 1e6 + 1;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long i = 2; i < n; i++)
    if (prime[i]) mem[i] = true;
}
vector<int> adj[51];
vector<bool> visited(51);
vector<int> team(51);
void solve(int s, int pno) {
  visited[s] = 1;
  team[s] = pno;
  for (auto x : adj[s]) {
    if (!visited[x]) {
      visited[x] = 1;
      solve(x, pno);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int pno = 1;
  for (long long i = 1; i < n + 1; i++) {
    if (team[i] == 0) {
      solve(i, pno);
    }
    pno++;
  }
  sort(team.begin(), team.end());
  long long ans = 1;
  for (long long i = 1; i < 51; i++) {
    long long cou = count(team.begin(), team.end(), team[i]);
    if (team[i] != 0) {
      ans *= 1 << (cou - 1);
    }
    i += cou - 1;
  }
  cout << ans;
  return 0;
}
