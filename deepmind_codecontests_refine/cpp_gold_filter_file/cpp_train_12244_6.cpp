#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
int main() {
  int n, k;
  cin >> n >> k;
  char ch;
  while (n--) {
    cin >> ch;
    if (++mp[ch] > k) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
