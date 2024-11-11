#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  long int a, i;
  long long int sum = 0, sum1 = 0;
  vector<long long int> v;
  for (i = 0; i < n; ++i) {
    cin >> a;
    sum += a;
    v.push_back(a);
  }
  sum1 = sum;
  sort(v.begin(), v.end());
  for (i = 0; i < v.size() - 1; ++i) {
    sum1 += v[0];
    sum = sum - v[0];
    sum1 += sum;
  }
  cout << sum1;
  return 0;
}
