#include <bits/stdc++.h>
using namespace std;
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
const long long mod = 1000000007;
const int maxn = 1000000;
bool arr[maxn + 1] = {false};
vector<int> produce_prim_number() {
  vector<int> prim;
  prim.push_back(2);
  int i, j;
  for (i = 3; i * i <= maxn; i += 2) {
    if (!arr[i]) {
      prim.push_back(i);
      for (j = i * i; j <= maxn; j += i) arr[j] = true;
    }
  }
  while (i < maxn) {
    if (!arr[i]) prim.push_back(i);
    i += 2;
  }
  return prim;
}
int cal(int x, int p) {
  int ans = 0;
  long long rec = p;
  while (x >= rec) {
    ans += x / rec;
    rec *= p;
  }
  return ans;
}
int pow(long long n, int k, int M) {
  long long ans = 1;
  while (k) {
    if (k & 1) {
      ans = (ans * n) % M;
    }
    n = (n * n) % M;
    k >>= 1;
  }
  return ans;
}
int combination(int n, int m) {
  const int M = mod;
  vector<int> prim = produce_prim_number();
  long long ans = 1;
  int num;
  for (int i = 0; i < prim.size() && prim[i] <= n; ++i) {
    num = cal(n, prim[i]) - cal(m, prim[i]) - cal(n - m, prim[i]);
    ans = (ans * pow(prim[i], num, M)) % M;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  cout << (2 * combination(2 * n - 1, n) - n) % mod << endl;
  return 0;
}
