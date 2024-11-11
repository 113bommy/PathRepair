#include <bits/stdc++.h>
using namespace std;
int n;
long long c[2];
map<long long, int> ways;
int main() {
  ways.clear();
  cin >> n >> c[0] >> c[1];
  if (c[0] > c[1]) swap(c[0], c[1]);
  if (n == 1) {
    cout << c[0] << endl;
    return 0;
  }
  if (c[0] == 0) {
    cout << c[1] * (long long)(n - 1) << endl;
    return 0;
  }
  ways[c[0]] = 1;
  if (c[0] == c[1])
    ways[c[0]] = 2;
  else
    ways[c[1]] = 1;
  n -= 2;
  long long ans = c[0] + c[1];
  while (n > 0) {
    map<long long, int>::iterator low = ways.lower_bound(1LL);
    long long cost = low->first;
    int num = low->second;
    ways.erase(low);
    if (n <= num) {
      ans += (long long)n * (cost + c[0] + c[1]);
      break;
    } else {
      long long left = cost + c[0];
      if (ways.find(left) == ways.end()) {
        ways[left] = num;
      } else
        ways[left] += num;
      long long right = cost + c[1];
      if (ways.find(right) == ways.end()) {
        ways[right] = num;
      } else
        ways[right] += num;
      n -= num;
      ans += (long long)num * (cost + c[0] + c[1]);
    }
  }
  cout << ans << endl;
  return 0;
}
