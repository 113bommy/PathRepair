#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long int> v, v1;
  long long int n, k, x;
  cin >> n >> k;
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      if (n / i == i)
        v.push_back(i);
      else {
        v.push_back(n / i);
        v.push_back(i);
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] < k) v1.push_back(v[i]);
  }
  long long int z = *max_element(v1.begin(), v1.end());
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == z) {
      x = v.size() - i;
      break;
    }
  }
  cout << k * x + z;
  return 0;
}
