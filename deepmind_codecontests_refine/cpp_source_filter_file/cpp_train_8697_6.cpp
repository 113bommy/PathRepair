#include <bits/stdc++.h>
int mod = (int)1e9 + 7;
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long int sum = 0;
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += (a[i] - 1);
    if (sum % 2 == 0)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}
