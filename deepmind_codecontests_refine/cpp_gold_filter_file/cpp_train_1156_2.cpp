#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  map<long long int, long long int> m;
  long long int k = n;
  long long int maxi = 1;
  while ((k % 2) == 0) {
    k = k / 2;
    m[2]++;
    maxi = max(maxi, (long long int)m[2]);
  }
  long long int i = 3;
  for (; k > 1; i += 2) {
    while (k % i == 0) {
      k = k / i;
      m[i]++;
      maxi = max(maxi, (long long int)m[i]);
    }
  }
  long long int product = 1;
  long long int total = 0;
  for (auto i : m) {
    total += maxi - i.second;
    product *= i.first;
  }
  cout << product << " ";
  if ((maxi & (maxi - 1)))
    cout << (1 + ceil(log2(maxi)));
  else {
    cout << ((total != 0) + ceil(log2(maxi)));
  }
  return 0;
}
