#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  long long sum(0), temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sum += temp;
  }
  sum % n == 0 ? cout << n : cout << n - 1 << endl;
  return 0;
}
