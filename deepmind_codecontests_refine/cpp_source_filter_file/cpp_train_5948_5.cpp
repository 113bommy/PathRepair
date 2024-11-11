#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long l;
  string s;
  cin >> l;
  cin >> s;
  long long d = 1;
  cout << s[0];
  for (long long i = 0; i < l;) {
    i = i + d;
    d++;
    cout << s[i];
  }
}
