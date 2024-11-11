#include <bits/stdc++.h>
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const int maxn = 1e5 + 111;
using namespace std;
int main() {
  int k = 0;
  string second;
  cin >> second;
  for (int i = 0; i < second.size(); i++) {
    if (second[i] >= '0' && second[i] <= '9' && (second[i] - '0') % 2 == 0)
      k++;
    else if (second[i] == 'a' || second[i] == 'e' || second[i] == 'i' ||
             second[i] == 'o' || second[i] == 'u')
      k++;
  }
  cout << k << endl;
  return 0;
}
