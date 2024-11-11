#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s(
      "312831303130313130313031312831303130313130313031312831303130313130313031"
      "312831303130313130313031");
  string sl(
      "312931303130313130313031312931303130313130313031312931303130313130313031"
      "312931303130313130313031");
  string t("");
  string k(
      "312931303130313130313031312831303130313130313031312931303130313130313031"
      "312831303130313130313031");
  string y(
      "312831303130313130313031312931303130313130313031312831303130313130313031"
      "312931303130313130313031");
  int flag = 0;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    if (a[0] == '2' && a[1] == '9') flag = 1;
    t += a;
  }
  if (t == k || t == y) {
    cout << "YES";
    return 0;
  }
  size_t f1 = sl.find(t);
  size_t f2 = s.find(t);
  size_t f3 = k.find(t);
  size_t f4 = y.find(t);
  if (f1 != string::npos)
    cout << "YES";
  else if (f2 != string::npos)
    cout << "YES";
  else if (f3 != string::npos)
    cout << "YES";
  else if (f4 != string::npos)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
