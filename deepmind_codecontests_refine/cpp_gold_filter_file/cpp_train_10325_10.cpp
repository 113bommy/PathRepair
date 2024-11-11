#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, sum = 0;
  cin >> n;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  if (v[0] > (sum - v[0])) {
    cout << "NO" << endl;
    return 0;
  }
  if (sum % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
