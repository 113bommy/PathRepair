#include <bits/stdc++.h>
using namespace std;
const long long mINF = 1000 * 1000 * 100;
const double ebs = 0.000001;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n > 27)
    cout << m;
  else {
    cout << m % (2 << n);
  }
  return 0;
}
