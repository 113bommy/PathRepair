#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long x;
  cin >> x;
  unsigned long long i, sum, temp, y;
  vector<unsigned long long> v;
  for (i = 1; i <= 100; i++) {
    temp = x - i;
    y = temp;
    if (temp <= 0) break;
    sum = 0;
    while (temp > 0) {
      sum += temp % 10;
      temp /= 10;
    }
    if ((sum + y) == x) {
      v.push_back(y);
    }
  }
  sort(v.begin(), v.end());
  cout << v.size() << '\n';
  for (i = 0; i < v.size(); i++) cout << v[i];
  return 0;
}
