#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  map<long long int, long long int> m;
  int flag = 1;
  for (int i = 1; i <= min(k, 100LL); ++i) {
    long long int val = n % i;
    m[val]++;
    if (m[val] > 1) {
      flag = 0;
      break;
    }
  }
  if (flag)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
