#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> next_two(n);
  auto ask = [](long long i, long long j) {
    cout << "?" << i + 1 << " " << j + 1 << endl;
    long long n;
    cin >> n;
    fflush(stdin);
    return n;
  };
  for (long long i = 0; i < n - 1; i++) {
    next_two[i] = ask(i, i + 1);
  }
  long long temp = ask(0, 2);
  vector<long long> ans(n);
  ans[1] = (next_two[0] + next_two[1] - temp) / 2;
  ans[0] = next_two[0] - ans[1];
  for (long long i = 2; i < n; i++) ans[i] = next_two[i - 1] - ans[i - 1];
  cout << "! ";
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
