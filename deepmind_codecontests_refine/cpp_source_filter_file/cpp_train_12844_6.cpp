#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using dl = double;
using ull = unsigned long long;
const long N = 3e5 + 10;
ll aarray[N];
ll magic[510][510];
vector<ll> primes;
bool check[1000001];
ll vis[N];
map<ll, ll> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string str;
  ll i, j, n, m, k, t;
  cin >> n;
  k = n % 4;
  if (k == 2 || k == 3) {
    cout << -1 << "\n";
    return 0;
  }
  for (i = 2; i <= n / 2; i++) {
    aarray[i - 1] = i;
    aarray[i] = n - i + 2;
    aarray[n - i + 1] = i - 1;
    aarray[n - i + 2] = n - i + 1;
  }
  if (n % 2) {
    aarray[(n / 2) + 1] = (n / 2) + 1;
  }
  for (i = 1; i <= n; i++) {
    cout << aarray[i] << " ";
  }
  cout << "\n";
  return 0;
}
