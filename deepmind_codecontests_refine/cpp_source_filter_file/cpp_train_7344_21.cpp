#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int sum = 0;
  int count = 0;
  int max = 0;
  int waste;
  cin >> n >> max >> waste;
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) cin >> vec[i];
  for (int j = 0; j < n; ++j) {
    if (vec[j] <= max) {
      sum += vec[j];
    }
    if (sum >= waste) {
      count += 1;
      sum = 0;
    }
  }
  cout << count << endl;
  return 0;
}
