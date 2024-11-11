#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string t;
  cin >> t;
  string s;
  cin >> s;
  int i = 0;
  int j = 0;
  int count = t.size();
  while (count--) {
    if (s[j] == t[i]) {
      j++;
      i++;
    } else {
      j++;
    }
  }
  cout << i + 1;
}
