#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using dl = double;
const int N = 2e5 + 10;
ll aarray[200000 + 10];
ll magic[101][101];
vector<ll> primes;
bool prime[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  string str, ptr, ans;
  ll a, b, c, d, e, f, x = INT_MAX, y, k, t, A = 0, mod, B = 0, L, j, i, l, r,
                       m, n, C = 0, sum = 0, sum1 = 0;
  vector<ll> v, v1;
  queue<ll> qu;
  cin >> str;
  cin >> n;
  ll cnt = 0, fla = 0;
  for (i = 1; i <= n; i++) {
    cin >> ptr;
    if (ptr.size() >= str.size()) {
      if (ptr.substr(0, str.size()) == str) {
        if (ptr < ans || ans == " ") ans = ptr;
      }
    }
  }
  if (ans == " ")
    cout << str << endl;
  else
    cout << ans << endl;
  return 0;
}
