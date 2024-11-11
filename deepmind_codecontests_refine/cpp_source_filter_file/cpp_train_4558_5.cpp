#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N;
  while (cin >> N) {
    ll x = 0;
    for (int i = 1; i <= N; ++i) x += i * (i + 1) / 2;
    for (int i = 1; i < N; ++i) {
      ll a, b;
      cin >> a >> b;
      if (b < a) swap(a, b);
      x -= a * (N - b + 1);
    }
    cout << x << endl;
  }
}
