#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const int N = 2e5 + 500;
vector<int> v[N];
long long int fact[N];
long long int dfs(int a, int dad) {
  long long int sum = 1;
  for (int i = 0; i < v[a].size(); i++) {
    if (v[a][i] != dad) (sum *= dfs(v[a][i], a)) %= mod;
  }
  return (sum * fact[v[a].size()]) % mod;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % mod;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  cout << (dfs(0, 0) * n) % mod << endl;
  return 0;
}
