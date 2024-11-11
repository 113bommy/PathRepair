#include <bits/stdc++.h>
using namespace std;
template <class t>
t mag(t a) {
  return a > 0 ? a : -a;
}
template <class T, class U>
T cdiv(T num, U den) {
  return (num / den) + ((num % den) > 0);
}
std::ifstream term("/dev/tty");
std::string tempstring;
using ll = int_fast64_t;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<ii>;
const int sij = 400010;
const ll mod = 1000000007ll;
ll n, m, vec[sij], prt[sij];
int esc(int tcase) {
  cin >> n >> m;
  for (auto i = 1; i <= m; i++) {
    cin >> vec[i];
  }
  ll sum = accumulate(vec + 1, vec + 1 + m, 0ll);
  if (n - vec[m] < m - 1 or sum < n) {
    cout << -1;
    return 0;
  }
  prt[m] = 1;
  sum -= vec[m];
  int prelen = vec[m];
  for (auto i = m - 1; i >= 1; i--) {
    sum -= vec[i];
    int rem = i - 1;
    int mini = max<ll>({prelen + 1 - vec[i] + 1, n - sum + 1 - vec[i], 1});
    int maxi = n - vec[i] + 2 - i;
    if (mini > maxi) {
      cout << -1;
      return 0;
    } else {
      prt[i] = mini;
      prelen = prt[i] + vec[i] - 1;
    }
  }
  for (auto i = 1; i <= m; i++) {
    cout << prt[i] << ' ';
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int i = 1; i <= tc; i++) esc(i);
}
