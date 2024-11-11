#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 123;
int n;
int p[N];
int rev(int x, int bits) {
  int res = 0;
  for (int i = 0; i < bits; i++) {
    if (!(x & (1 << i))) {
      res |= (1 << i);
    }
  }
  return res;
}
void solve(int n) {
  while (n > 0) {
    int t = 0;
    while ((1 << (t + 1)) - 1 <= n) t++;
    int to = n;
    for (int x = 0; (1 << t) + x <= n; x++) {
      int l = (1 << t) - 1 - x;
      int r = (1 << t) + x;
      p[l] = r;
      p[r] = l;
      to = l;
    }
    n = to - 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  solve(n);
  long long sum = 0;
  for (int i = 0; i <= n; i++) {
    sum += i ^ p[i];
  }
  cout << sum << "\n";
  for (int i = 0; i <= n; i++) cout << p[i] << " ";
  cout << "\n";
  return 0;
}
