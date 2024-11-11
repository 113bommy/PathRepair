#include <bits/stdc++.h>
using namespace std;
int main() {
  string second;
  cin >> second;
  map<char, int> m;
  for (int i = 0; i < 10; i++) {
    m[char(i + '0')] = i;
  }
  int cnt = 10;
  for (char c = 'a'; c <= 'z'; c++) {
    m[c] = cnt++;
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    m[c] = cnt++;
  }
  m['-'] = cnt++;
  m['_'] = cnt++;
  long long ans = 1;
  for (int i = 0; i < second.size(); i++) {
    int x = m[second[i]];
    for (int j = 0; j < 6; j++) {
      if (!(x & (1 << j))) ans *= 3, ans %= 1000000007;
    }
  }
  cout << ans;
}
