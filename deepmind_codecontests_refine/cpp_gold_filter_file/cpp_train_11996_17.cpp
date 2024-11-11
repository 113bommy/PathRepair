#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A;
  int sum = 0;
  int invalid = 1;
  int to_add;
  for (int i = 1; i <= n; i++) {
    int next_sum = sum + A.size() / 2;
    if (next_sum >= m) {
      invalid = 0;
      to_add = 2 * (next_sum - m);
      break;
    }
    sum = next_sum;
    A.push_back(i);
  }
  if (invalid) {
    cout << -1 << '\n';
    return 0;
  }
  A.push_back(A.size() + 1 + to_add);
  int randombignumber = 50000000;
  while (A.size() < n) {
    A.push_back(randombignumber);
    randombignumber += 2 * n + 1;
  }
  for (auto i : A) cout << i << ' ';
  cout << '\n';
  return 0;
}
