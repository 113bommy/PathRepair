#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, l = 0, r = 1000000000;
  map<string, long long int> mp;
  string s;
  cin >> n;
  cout << 0 << " " << 1 << "\n";
  fflush(stdout);
  cin >> s;
  mp[s] = 0;
  if (s == "white")
    mp["black"] = 1;
  else
    mp["white"] = 1;
  long long int max0 = 0, min1 = 1000000000;
  for (long long int i = 1; i < n; i++) {
    long long int mid = (l + r) / 2;
    cout << mid << " " << 1 << "\n";
    fflush(stdout);
    cin >> s;
    if (mp[s] == 0) {
      l = mid + 1;
      max0 = max(max0, mid);
    } else {
      r = mid - 1;
      min1 = min(min1, mid);
    }
  }
  cout << max0 << " " << 2 << " " << min1 << " " << 0;
  fflush(stdout);
  return 0;
}
