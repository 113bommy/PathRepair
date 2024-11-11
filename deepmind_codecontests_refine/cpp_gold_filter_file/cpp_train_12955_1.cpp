#include <bits/stdc++.h>
using namespace std;
long long n, ones[17];
int dfs(long long n, int i) {
  long long t = n / ones[i];
  long long r = n % ones[i];
  if (r == 0) return t * i;
  return min(t * i + dfs(r, i - 1), (t + 1) * i + dfs(ones[i] - r, i - 1));
}
int main() {
  cin >> n;
  ones[0] = 0;
  for (int i = 1; i <= 16; i++) ones[i] = ones[i - 1] * 10 + 1;
  cout << dfs(n, 16) << endl;
  return 0;
}
