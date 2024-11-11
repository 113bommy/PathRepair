#include <bits/stdc++.h>
using namespace std;
struct cl {};
int F(string str) {
  int res = 0;
  if ((int)(str).size() == 2) {
    res = (int)(str[0] - '0') * 10 + (int)(str[1] - '0');
  } else {
    res = (int)(str[0] - '0');
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int(i) = 0; (i) < (n); (i)++) {
    string str;
    cin >> str;
    int h, m, c;
    string str1;
    str1 += str[0];
    str1 += str[1];
    h = F(str1);
    str1 = "";
    str1 += str[3];
    str1 += str[4];
    m = F(str1);
    c = 60 * m + 3600 * h;
    arr.push_back(c);
  }
  sort((arr).begin(), (arr).end());
  int ans = 0;
  for (int(i) = 0; (i) < ((int)(arr).size() - 1); (i)++) {
    ans = max(ans, arr[i + 1] - arr[i] - 60);
  }
  if (n == 1) {
    cout << "23:59";
    return 0;
  }
  ans = max(ans, (24 * 3600 + arr[0]) - arr[n - 1] - 60);
  int ansH = ans / 3600;
  int ansM = (ans - ansH * 3600) / 60;
  string out;
  if (ansH < 10) {
    out += "0";
    out += (char)('0' + ansH);
    out += ":";
  } else {
    out += (char)('0' + ansH / 10);
    out += (char)('0' + ansH % 10);
    out += ":";
  }
  if (ansM < 10) {
    out += "0";
    out += (char)('0' + ansM);
  } else {
    out += (char)('0' + ansM / 10);
    out += (char)('0' + ansM % 10);
  }
  cout << out;
  return 0;
}
