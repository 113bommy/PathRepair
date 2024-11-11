#include <bits/stdc++.h>
using namespace std;
bool DESC(long long int a, long long int b) { return (a > b); }
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long int n = 0, k = 0, i = 0;
  vector<long long int> vec;
  cin >> n >> k;
  if (n % (2 * k + 1) == 0) {
    for (i = k + 1; i <= n; i += 2 * k + 1) vec.push_back(i);
  } else if (n % (2 * k + 1) <= k) {
    for (i = 1; i <= n; i += 2 * k + 1) vec.push_back(i);
  } else {
    for (i = n % (2 * k + 1) - k; i <= n; i += 2 * k + 1) vec.push_back(i);
  }
  cout << vec.size() << endl;
  for (i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  return 0;
}
