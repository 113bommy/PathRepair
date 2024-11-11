#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long int sum = 0;
  for (int i = 0; i < n; i++) sum += v[i];
  if (sum % 2 == 0 && sum >= 2 * v[n - 1])
    cout << "YES";
  else
    cout << "NO";
}
