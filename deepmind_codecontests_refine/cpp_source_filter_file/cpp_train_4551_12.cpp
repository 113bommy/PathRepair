#include <bits/stdc++.h>
using namespace std;
long long int roof(double x) {
  if (x - floor(x) != 0) return floor(x) + 1;
  return floor(x);
}
int main() {
  long long int n = 0, input = 0, i = 0, sum = 0;
  long long int ans = 0, counter = 0;
  double x = 0;
  vector<long long int> vec;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> input;
    vec.push_back(input);
    sum += input;
  }
  x = (double)n * 4.5;
  if (sum >= x) {
    cout << 0;
    return 0;
  }
  ans = roof(x - sum);
  sort(vec.begin(), vec.end());
  i = 0;
  while (ans > 0) {
    ans -= (5 - vec[i]);
    counter++;
  }
  cout << counter;
  return 0;
}
