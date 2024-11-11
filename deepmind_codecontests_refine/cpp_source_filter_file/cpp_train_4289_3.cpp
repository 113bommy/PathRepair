#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10, maxe = 15;
long long n, k, x, ans = -1;
long long fact[maxe], A[maxe], use[maxe];
void lucky_generator(long long a) {
  if (a > x) return;
  ans++;
  lucky_generator(a * 10 + 4);
  lucky_generator(a * 10 + 7);
}
bool is_lucky(long long a) {
  if (a < 3) return 0;
  a++;
  while (a) {
    if (a % 10 != 4 && a % 10 != 7) return 0;
    a /= 10;
  }
  return 1;
}
void solve(long long index, long long size) {
  if (index == size) return;
  int a = k / fact[size - index - 1] + 1, i = 0;
  k -= (a - 1) * fact[size - index - 1];
  for (;; i++) {
    if (!use[i]) {
      a--;
      if (!a) break;
    }
  }
  A[index] = i;
  use[i] = 1;
  if (is_lucky(index + x) && is_lucky(i + x)) {
    ans++;
  }
  solve(index + 1, size);
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < maxe + 1; i++) fact[i] = i * fact[i - 1];
  cin >> n >> k;
  k--;
  if (n < maxe && k > fact[n]) {
    cout << "-1\n";
    return 0;
  }
  x = max(0ll, n - maxe);
  lucky_generator(0);
  solve(0ll, n - x);
  cout << ans << endl;
}
