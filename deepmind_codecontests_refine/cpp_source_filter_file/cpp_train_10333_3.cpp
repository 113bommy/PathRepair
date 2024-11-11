#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const long long INF = 1e18;
const long long mod = 998244353;
const double Pi = acos(-1);
void Fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n;
int cur = 1, best = 0;
int f(int k) { return n - k - (n + k - 1) / k + 1; }
set<int> S;
signed main() {
  Fastio();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (f(i) > best) {
      best = f(i);
      cur = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((i - 1) % cur != 0) {
      S.insert(i);
    }
  }
  while (S.size() >= cur) {
    cout << cur << ' ';
    for (int i = 0; i < cur; i++) {
      cout << *S.begin() << ' ';
      S.erase(*S.begin());
    }
    cout << endl;
    int temp;
    cin >> temp;
    for (int i = 0; i < cur; i++) {
      if ((temp - 1) % cur != 0) {
        S.insert(temp);
      }
      temp = (temp + 1) % cur;
    }
  }
  cout << 0 << endl;
}
