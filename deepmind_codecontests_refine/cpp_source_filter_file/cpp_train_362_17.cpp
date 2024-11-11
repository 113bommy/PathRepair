#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long n, m, genres[11];
long long combo(int a) { return a * (a - 1) / 2; }
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    genres[a]++;
  }
  long long ans = combo(n);
  for (int i = 0; i < 11; i++) ans -= combo(genres[i]);
  cout << ans;
  return 0;
}
