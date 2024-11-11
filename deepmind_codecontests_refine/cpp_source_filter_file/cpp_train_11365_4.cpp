#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int inverse(long long int i) {
  if (i == 1) return 1;
  return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}
string sum1(string d1, string d2) {
  int s, c = 0;
  int n1 = d1.size(), n2 = d2.size();
  int pos = 1;
  string res;
  while (pos <= max(n1, n2)) {
    int sum1 = 0, carry1 = 0;
    if (n1 - pos > -1) sum1 += (d1[n1 - pos] - '0');
    if (n2 - pos > -1) sum1 += (d2[n2 - pos] - '0');
    sum1 += c;
    res.push_back(sum1 % 10 + '0');
    c = sum1 / 10;
    pos++;
  }
  if (c != 0) res.push_back(c + '0');
  string res2;
  for (int i = res.size() - 1; i > -1; --i) res2.push_back(res[i]);
  return res2;
}
int main() {
  int l;
  cin >> l;
  string s1;
  cin >> s1;
  int min1 = l;
  int ans1, ans2 = -1;
  for (int i = 1; i < l; ++i) {
    if (s1[i] != 0) {
      if (max(i, l - i) < min1) {
        ans1 = i;
        min1 = max(i, l - i);
      }
    }
  }
  for (int i = 1; i < l; ++i) {
    if (s1[i] != 0) {
      if (max(i, l - i) == min1 && i != ans1) {
        ans2 = i;
        break;
      }
    }
  }
  string d1, d2;
  for (int i = 0; i < ans1; ++i) d1.push_back(s1[i]);
  for (int i = ans1; i < l; ++i) d2.push_back(s1[i]);
  string s4 = sum1(d1, d2);
  string s5;
  if (ans2 != -1) {
    d1.clear();
    d2.clear();
    for (int i = 0; i < ans2; ++i) d1.push_back(s1[i]);
    for (int i = ans2; i < l; ++i) d2.push_back(s1[i]);
    s5 = sum1(d1, d2);
  }
  if (ans2 == -1)
    cout << s4;
  else {
    if (s4 < s5)
      cout << s4;
    else
      cout << s5;
  }
}
