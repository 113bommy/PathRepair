#include <bits/stdc++.h>
using namespace std;
vector<long long> vll;
long long to_dig(string str);
long long p10(long long i);
map<string, bool> mp;
void pro(string str) {
  long long len = str.size();
  for (int i = 0; i < 19 - len; i++) str += '0';
  sort(str.begin(), str.end());
  if (mp[str] == 1) {
    return;
  }
  mp[str] = 1;
  vll.push_back(to_dig(str));
  while (next_permutation(str.begin(), str.end())) {
    vll.push_back(to_dig(str));
  }
}
long long to_dig(string str) {
  long long sum = 0;
  for (int j = str.size() - 1; j >= 0; j--) {
    sum += (str[j] - '0') * p10(str.size() - 1 - j);
  }
  return sum;
}
long long p10(long long i) {
  long long mul = 1;
  while (i--) mul *= 10;
  return mul;
}
int main() {
  string str;
  long long len;
  for (int i = 0; i < 10; i++) {
    string str1;
    str1 += to_string(i);
    pro(str1);
    for (int j = 0; j < 10; j++) {
      string str2;
      str2 = str1 + to_string(j);
      pro(str2);
      for (int k = 0; k < 10; k++) {
        string str3;
        str3 = str2 + to_string(k);
        pro(str3);
      }
    }
  }
  long long t, l, r;
  sort(vll.begin(), vll.end());
  cin >> t;
  while (t--) {
    cin >> l >> r;
    auto it1 = lower_bound(vll.begin(), vll.end(), l);
    auto it2 = lower_bound(vll.begin(), vll.end(), r);
    if ((l == r && *it1 != l) || *it1 > r) {
      cout << "0"
           << "\n";
      continue;
    }
    if (*it2 > r) it2--;
    cout << it2 - it1 + 1 << "\n";
  }
}
