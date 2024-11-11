#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<long long> v;
  long long n;
  cin >> n;
  if (n % 2 != 0)
    cout << n / 2 << " " << n / 2 + 1;
  else if (n % 4 == 0)
    cout << n / 2 - 1 << " " << n - (n / 2) + 1;
  else
    cout << n / 2 - 2 << " " << n / 2 + 2;
}
