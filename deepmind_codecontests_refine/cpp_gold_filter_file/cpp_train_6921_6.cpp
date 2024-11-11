#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  long long coun = 0, presum = 0;
  for (int i = 0; i < n; i++) {
    if (presum <= vec[i]) {
      coun++;
      presum += vec[i];
    }
  }
  cout << coun;
}
