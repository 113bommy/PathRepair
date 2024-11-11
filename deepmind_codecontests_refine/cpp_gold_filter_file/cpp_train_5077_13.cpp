#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, even = 0, odd = 0;
  cin >> n >> k;
  int a[n];
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0)
      even++;
    else
      odd++;
    if (even == odd && i != n - 1) {
      v.push_back(abs(a[i] - a[i + 1]));
    }
  }
  sort(v.begin(), v.end());
  int i = 0, sum = 0;
  while (i < v.size() && sum + v[i] <= k) {
    sum += v[i];
    i++;
  }
  cout << i << '\n';
}
