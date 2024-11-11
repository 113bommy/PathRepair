#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, p;
  cin >> p >> k;
  if (p < k) {
    cout << 1 << endl << p << endl;
    return 0;
  }
  vector<long long int> hehe;
  long long int isneg = 0;
  long long int prev = p;
  long long int next;
  while (prev >= k || isneg != 0) {
    if (isneg == 0) {
      next = prev / k;
      prev = next;
      isneg = 1;
      next *= -1;
      hehe.push_back(next);
    } else {
      next = (prev + k - 1) / k;
      isneg = 0;
      prev = next;
      hehe.push_back(next);
    }
  }
  if (prev != 0) hehe.push_back(0);
  long long int ans = hehe.size();
  cout << ans << endl;
  cout << p + (hehe[0] * k) << " ";
  for (long long int i = 1; i < ans; i++) {
    cout << hehe[i - 1] + (hehe[i] * k) << " ";
  }
  cout << endl;
  return 0;
}
