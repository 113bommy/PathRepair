#include <bits/stdc++.h>
using namespace std;
string findSum(string str1, string str2) {
  if (str1.length() > str2.length()) swap(str1, str2);
  string str = "";
  int n1 = str1.length(), n2 = str2.length();
  int diff = n2 - n1;
  int carry = 0;
  for (int i = n1 - 1; i >= 0; i--) {
    int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  for (int i = n2 - n1 - 1; i >= 0; i--) {
    int sum = ((str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  if (carry) str.push_back(carry + '0');
  reverse(str.begin(), str.end());
  return str;
}
string com(string a, string b) {
  int n1 = a.size(), n2 = b.size();
  if (n1 < n2)
    return a;
  else if (n1 > n2)
    return b;
  else {
    if (a > b)
      return b;
    else
      return a;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v;
  int x = (n + 1) / 2;
  if (s[x] != '0') v.push_back(x);
  for (int i = x - 1; i > 0; i--) {
    if (s[i] != '0') {
      v.push_back(i);
      break;
    }
  }
  for (int i = x + 1; i < n; i++) {
    if (s[i] != '0') {
      v.push_back(i);
      break;
    }
  }
  if (n % 2 == 1) {
    if (s[x + 1] != '0') v.push_back(x);
  }
  int n1 = v.size();
  string ans(n, '9');
  for (int i = 0; i <= n1 - 1; i++) {
    string a = s.substr(0, v[i]);
    string b = s.substr(v[i], n - v[i]);
    string c = findSum(a, b);
    ans = com(ans, c);
  }
  cout << ans << '\n';
  return 0;
}
