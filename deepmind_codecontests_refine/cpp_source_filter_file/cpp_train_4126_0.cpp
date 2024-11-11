#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  std::vector<long int> v;
  for (int i = 0; i < 100; i++) {
    long int tmp = n - i;
    int sum = 0;
    while (tmp) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (sum == i) {
      v.push_back(n - i);
    }
  }
  cout << v.size() << endl;
  for (long int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
  return 0;
}
