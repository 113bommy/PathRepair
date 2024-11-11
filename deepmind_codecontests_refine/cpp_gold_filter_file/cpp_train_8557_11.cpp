#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  long long log_2 = floor(log2(k));
  long long row = (1LL << log_2);
  long long extra = k - (row);
  long long ans_odd = (n - extra) / row;
  if (ans_odd % 2 == 0) ans_odd--;
  log_2 = (long long)floor(log2(k + 1)) - 1;
  row = 1LL << log_2;
  extra = k - (row * 2 - 1);
  long long ans_even = (n - extra) / row;
  if (ans_even & 1) ans_even--;
  cout << max(ans_even, ans_odd);
  return 0;
}
