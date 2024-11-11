#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y / 2, x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
string add(string str1, string str2) {
  if (str1.length() > str2.length()) swap(str1, str2);
  string str = "";
  int n1 = str1.length(), n2 = str2.length();
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());
  int carry = 0;
  for (int i = 0; i < n1; i++) {
    int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  for (int i = n1; i < n2; i++) {
    int sum = ((str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  if (carry) str.push_back(carry + '0');
  reverse(str.begin(), str.end());
  return str;
}
bool isSmaller(string str1, string str2) {
  int n1 = str1.length(), n2 = str2.length();
  if (n1 < n2) return true;
  if (n2 < n1) return false;
  for (int i = 0; i < n1; i++)
    if (str1[i] < str2[i])
      return true;
    else if (str1[i] > str2[i])
      return false;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  long long i;
  string s;
  cin >> n >> s;
  if (n % 2 == 0) {
    string temp = "";
    for (i = 0; i < n / 2; i++) temp += s[i];
    for (i = n / 2; i < n; i++) {
      if (s[i] != '0') break;
      temp += s[i];
    }
    long long j;
    string temp2 = "";
    for (j = i; j < n; j++) temp2 += s[j];
    string x = add(temp, temp2);
    for (i = n / 2; i >= 0; i--) {
      if (s[i] != '0') break;
    }
    temp = "";
    temp2 = "";
    for (j = i; j < n; j++) temp += s[j];
    for (j = 0; j < i; j++) temp2 += s[j];
    string y = add(temp, temp2);
    if (isSmaller(x, y))
      cout << x;
    else
      cout << y;
    return 0;
  } else {
    string temp = "";
    for (i = 0; i < n / 2; i++) temp += s[i];
    for (i = n / 2; i < n; i++) {
      if (s[i] != '0') break;
      temp += s[i];
    }
    long long j;
    string temp2 = "";
    for (j = i; j < n; j++) temp2 += s[j];
    string x = add(temp, temp2);
    for (i = n / 2; i >= 0; i--) {
      if (s[i] != '0') break;
    }
    temp = "";
    temp2 = "";
    for (j = i; j < n; j++) temp += s[j];
    for (j = 0; j < i; j++) temp2 += s[j];
    string y = add(temp, temp2);
    if (isSmaller(y, x)) x = y;
    temp = "";
    for (i = 0; i <= n / 2; i++) temp += s[i];
    for (i = n / 2 + 1; i < n; i++) {
      if (s[i] != '0') break;
      temp += s[i];
    }
    temp2 = "";
    for (j = i; j < n; j++) temp2 += s[j];
    string xx = add(temp, temp2);
    for (i = n / 2 + 1; i >= 0; i--) {
      if (s[i] != '0') break;
    }
    temp = "";
    temp2 = "";
    for (j = i; j < n; j++) temp += s[j];
    for (j = 0; j < i; j++) temp2 += s[j];
    string yy = add(temp, temp2);
    if (isSmaller(yy, xx)) xx = yy;
    if (isSmaller(x, xx))
      cout << x;
    else
      cout << xx;
    return 0;
  }
}
