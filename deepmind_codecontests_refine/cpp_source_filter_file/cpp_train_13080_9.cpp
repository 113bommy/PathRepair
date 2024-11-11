#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
using namespace std;
int a[100000 + 100];
long long sums[100000 + 100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s, f;
  cin >> n;
  for (int i = (1); i < (n + 1); i++) {
    cin >> a[i];
    sums[i] = sums[i - 1] + a[i];
  }
  cin >> s >> f;
  int x = f - s;
  long long m = 0;
  int ans = ((1LL << 31) - 1);
  int curr = 1;
  for (int i = (1); i < (n + 1); i++) {
    int end = i + x - 1;
    long long s = 0;
    if (end <= n) {
      s = sums[end] - sums[i - 1];
    } else {
      s = sums[n] - sums[i - 1] + sums[end - n];
    }
    if (s <= 0) exit(1);
    if (s > m) {
      m = s;
      ans = curr;
    } else if (s == m) {
      ans = min(ans, curr);
    }
    curr--;
    if (curr == 0) curr = n;
  }
  if (ans <= 0 || ans > n) {
    return 1;
  }
  cout << ans << endl;
  return 0;
}
