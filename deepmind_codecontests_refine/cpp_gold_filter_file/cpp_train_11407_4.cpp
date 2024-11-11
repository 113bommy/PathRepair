#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> m;
  long long n, x, A[300005], ans = 0;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    m[(A[i] ^ x)]++;
  }
  for (int i = 0; i < n; ++i) {
    m[(A[i] ^ x)]--;
    ans += m[A[i]];
  }
  cout << ans;
}
