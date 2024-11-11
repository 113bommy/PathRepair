#include <bits/stdc++.h>
using namespace std;
void fuck_it() {
  long long n;
  cin >> n;
  string k;
  cin >> k;
  long long count = 0;
  vector<char> all{'R', 'G', 'B'};
  for (long long i = 1; i < k.length(); i++) {
    if (k[i] == k[i - 1]) {
      for (char c : all) {
        if (k[i] != c) {
          k[i] = c;
          if (k[i] == k[i + 1]) {
            continue;
          } else if (k[i] != k[i + 1] && k[i] != k[i - 1]) {
            count++;
            i++;
            break;
          }
        }
      }
    }
  }
  cout << count << "\n";
  cout << k << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    fuck_it();
  }
}
