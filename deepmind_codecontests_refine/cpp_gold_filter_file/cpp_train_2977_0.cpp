#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, count = 0, sum = 1, m;
  vector<int> v;
  cin >> n >> k;
  m = n;
  for (int i = 2; i * i <= n; i++) {
    while ((m % i == 0) && (count < k - 1)) {
      sum *= i;
      v.push_back(i);
      count++;
      m /= i;
    }
  }
  if (sum * m == n && m != 1 && count + 1 == k) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << m;
  } else
    cout << -1;
  return 0;
}
