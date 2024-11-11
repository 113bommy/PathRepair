#include <bits/stdc++.h>
using namespace std;
int dx4[4] = {0, -1, 0, 1};
int dy4[4] = {1, 0, -1, 0};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int Power(int base, int exp) {
  int ans = 1;
  while (exp > 0) {
    if (exp & 1) ans = (1LL * ans * base) % 1000000007;
    exp = exp >> 1;
    base = (1LL * base * base) % 1000000007;
  }
  return ans;
}
void input() {
  long long int a, b, m;
  cin >> a >> b >> m;
  long long int x = 1;
  for (int i = 0; i < 9; i += 1) x = (x * 10) % m;
  for (int i = 0; i < min(m - 1, a) + 1; i += 1) {
    int my = (m - (x * i) % m) % m;
    if (my > min(b, m - 1)) {
      cout << 1 << ' ';
      int d = (i == 0 ? 0 : log10(i)) + 1;
      for (int j = 0; j < 9 - d; j += 1) cout << 0;
      cout << i << '\n';
      return;
    }
  }
  cout << 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q--) input();
}
