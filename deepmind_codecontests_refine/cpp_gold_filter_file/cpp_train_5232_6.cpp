#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
using namespace std;
const int MAXN = 3000 + 5;
int a[MAXN];
int b[MAXN];
int p[MAXN];
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  int qr;
  for (cin >> qr; qr > 0; qr--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    unordered_map<int, int> u;
    for (int i = 0; i < n; i++) {
      u[b[i]] = i;
      p[i] = 0;
    }
    p[n] = 0;
    int ans = 1;
    for (int i = n - 1; i >= 0; i--) {
      int k = u[a[i]];
      p[k] = p[k + 1] + 1;
      ans = max(ans, p[k]);
    }
    cout << n - ans << '\n';
  }
}
