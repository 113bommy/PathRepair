#include <bits/stdc++.h>
using namespace std;
bool chmin(int64_t& a, const int64_t& b) { return b < a ? a = b, 1 : 0; }
bool chmax(int64_t& a, const int64_t& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
const int N = 1e6 + 1;
int check(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return 0;
}
void run_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<int> second;
  int temp = n;
  while (temp % 4 == 0) {
    temp /= 4;
    second.insert(4);
  }
  for (int i = 3; i * i <= temp; i++) {
    if (temp % i == 0) {
      while (temp % i == 0) {
        temp /= i;
        second.insert(i);
      }
    }
  }
  if (temp > 2) {
    if (temp % 2 == 0) temp /= 2;
    second.insert(temp);
  }
  for (auto x : second) {
    temp = n / x;
    for (int i = 0; i < temp; i++) {
      bool flag = true;
      for (int j = i; j < n; j += temp) {
        if (a[j] == 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << "YES\n";
        return;
      }
    }
  }
  puts("NO");
}
auto clk = clock();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    run_case();
  }
  return 0;
}
