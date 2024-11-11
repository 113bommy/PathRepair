#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    long long int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  if (n % 2) {
    cout << v[(n - 1) / 2 + 2];
    return 0;
  }
  cout << v[n / 2 - 1];
  return 0;
}
