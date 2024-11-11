#include <bits/stdc++.h>
using namespace std;
vector<long long> superLucky;
void solve(long long num = 0, long long fours = 0, long long sevens = 0) {
  if (num > 1e9) return;
  if (num && fours == sevens) superLucky.push_back(num);
  solve(num * 10 + 4, fours + 1, sevens);
  solve(num * 10 + 7, fours, sevens + 1);
}
int main() {
  solve();
  sort(superLucky.begin(), superLucky.end());
  long long n, out;
  cin >> n;
  for (auto i : superLucky)
    if (i >= n) return cout << i, 0;
  cout << superLucky.back();
}
