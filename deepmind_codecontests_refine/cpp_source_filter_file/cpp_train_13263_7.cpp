#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> mp;
vector<long long int> v;
int main() {
  long long int l = 0, n, i, j = 0, bit = 0;
  string s;
  cin >> s;
  s += ',';
  for (i = 0; i < s.length(); i++) {
    if (s[i] == ',') {
      long long int numb = 0;
      for (j = l; j < i; j++) {
        numb = numb * 10 + 10 * (s[j] - '0');
      }
      numb /= 10;
      v.push_back(numb);
      l = i + 1;
    }
  }
  for (i = 0; i < v.size(); i++) {
    mp[v[i]]++;
  }
  l = -1;
  string ans = "";
  for (i = 0; i <= 1000; i++) {
    if (mp[i] == 0) {
      if (mp[i - 1] != 0 && l != i - 1) {
        if (bit == 0)
          cout << l << "-" << i - 1;
        else
          cout << "," << l << " " << i - 1;
        bit = 1;
        l = -1;
      } else if (mp[i - 1] != 0) {
        if (bit == 0)
          cout << i - 1;
        else
          cout << "," << i - 1;
        bit = 1;
        l = -1;
      }
    } else {
      if (l == -1) l = i;
    }
  }
  return 0;
}
