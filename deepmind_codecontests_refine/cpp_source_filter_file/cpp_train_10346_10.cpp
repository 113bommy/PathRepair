#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, f, t, joy = -99999999;
  cin >> n >> k;
  while (n--) {
    cin >> f >> t;
    if (t > k)
      joy = max(joy, f - (t - k));
    else
      joy = max(joy, f);
  }
  cout << joy << endl;
}
