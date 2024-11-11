#include <bits/stdc++.h>
using namespace std;
const long long MXN = 1e5 + 1;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string second, t;
  cin >> second >> t;
  long long pos = (int)(second).size();
  for (int i = 1; i < (int)(second).size(); i++) {
    if (second[i] >= second[0]) {
      pos = i;
      break;
    }
  }
  for (int i = 0; i < pos; i++) {
    cout << second[i];
  }
  cout << t[0];
  return 0;
}
