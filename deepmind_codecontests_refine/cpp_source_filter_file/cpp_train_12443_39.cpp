#include <bits/stdc++.h>
using namespace std;
const int maxbit = 5;
int main() {
  ::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long s, x;
  cin >> s >> x;
  long long save = x;
  vector<int> bit;
  vector<int> a, b;
  long long sum = 0;
  long long deg = 1;
  for (int i = 0; i < maxbit; ++i) {
    a.push_back(x % 2);
    sum += deg * a.back();
    b.push_back(0);
    x /= 2;
    deg <<= 1;
  }
  deg >>= 1;
  for (int i = maxbit - 1; i >= 0; i--) {
    if ((sum + 2 * deg <= s) && (a[i] + b[i] == 0))
      a[i] = 1, b[i] = 1, sum += 2 * deg;
    deg >>= 1;
  }
  if (sum != s) {
    cout << 0;
    return 0;
  }
  long long answer = 1;
  for (int i = 0; i < maxbit; ++i)
    if (a[i] + b[i] == 1) answer <<= 1;
  if (s == x)
    cout << answer - 2;
  else
    cout << answer;
  return 0;
}
