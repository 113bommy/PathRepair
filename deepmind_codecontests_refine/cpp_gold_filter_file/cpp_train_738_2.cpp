#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 10;
unordered_map<int, bool> cash;
vector<int> prime;
bitset<maxn> used;
void erat() {
  for (int i = 2; i <= (int)1e5; ++i) {
    if (!used[i]) {
      prime.push_back(i);
      for (long long j = i; j <= (int)1e5; j *= i) {
        used[j] = true;
      }
    }
  }
}
bool is_prime(long long n) {
  bool res = true;
  for (int i = 2; 1ll * i * i <= n; ++i) {
    if (n % i == 0) {
      res = false;
    }
  }
  return res;
}
int solve(long long n) {
  for (int i : prime) {
    if (n % i == 0) {
      return n - i;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  erat();
  long long n;
  cin >> n;
  if (is_prime(n)) {
    cout << 1 << endl;
    return 0;
  }
  long long ans = 0;
  if (n % 2) {
    ++ans;
    for (int i : prime) {
      if (n % i == 0) {
        n -= i;
        break;
      }
    }
  }
  ans += n / 2;
  cout << ans << endl;
  return 0;
}
