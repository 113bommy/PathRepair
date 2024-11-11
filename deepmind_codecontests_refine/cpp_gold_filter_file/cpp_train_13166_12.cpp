#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, len, alpha[26];
  for (i = 0; i < 26; i++) cin >> alpha[i];
  long long ans = 0, sum = 0;
  string str;
  cin >> str;
  len = str.length();
  map<long long, long long> m[26];
  for (i = 0; i < len; i++) {
    int x = str[i] - 'a';
    ans += m[x][sum];
    m[x][sum += alpha[x]]++;
  }
  cout << ans << endl;
  return 0;
}
