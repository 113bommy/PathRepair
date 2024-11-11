#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, data, prev = 0, energy = 0;
  cin >> n;
  vector<long long int> v1(n);
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> data;
    if (energy < (data - prev)) {
      ans += ((data - prev) - energy);
      energy = 0;
      prev = data;
    } else {
      energy += (prev - data);
      prev = data;
    }
  }
  cout << ans;
}
