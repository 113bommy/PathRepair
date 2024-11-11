#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pli = pair<long long, int>;
using ll = long long;
const int N = 2e3 + 7, Max = 5e3 + 7;
const ll mod = 1e9 + 7;
ll n, A, B;
ll a[N], cnt[Max], suff[Max];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      for (int j = 1; j < i; ++j) ++cnt[abs(a[i] - a[j])];
    }
    for (int i = 5000; i > 0; --i) suff[i] = suff[i + 1] + cnt[i];
    A = n * (n - 1) / 2;
    A = A * A * A;
    for (int i = 1; i < 5000; ++i)
      for (int j = 1; i + j < 5000; ++j) B += cnt[i] * cnt[j] * suff[i + j + 1];
    cout << (double)B / A;
  }
  return 0;
}
