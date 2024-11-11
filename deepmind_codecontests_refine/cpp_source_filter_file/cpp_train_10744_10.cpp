#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio;
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  while (n--) {
    vector<long long> a(3);
    for (long long i = 0; i < 3; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[2] <= (a[1] + a[0]))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
