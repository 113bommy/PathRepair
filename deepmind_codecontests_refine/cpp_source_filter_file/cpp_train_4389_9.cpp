#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, carr = 0, i;
  cin >> n;
  string s1, s2;
  getline(cin, s1);
  getline(cin, s1);
  getline(cin, s2);
  map<long long, char> mp;
  vector<long long> v;
  for (i = 1; i <= 26; i++) {
    mp[i] = (char)('a' + i - 1);
  }
  for (i = n - 1; i >= 0; i--) {
    long long temp = (s1[i] - 'a' + s2[i] - 'a' + carr);
    if (temp > 26) {
      temp -= 26;
      carr = 1;
    } else
      carr = 0;
    v.push_back(temp);
  }
  for (i = v.size() - 1; i >= 0; i--) {
    if (carr == 1) {
      cout << (char)('a' + ((v[i] + 26) / 2));
    } else {
      cout << (char)('a' + (v[i] / 2));
    }
    if ((v[i] + 26) % 2 == 1) {
      carr = 1;
    } else
      carr = 0;
  }
  return 0;
}
