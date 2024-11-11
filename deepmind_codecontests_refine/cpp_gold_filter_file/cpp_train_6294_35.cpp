#include <bits/stdc++.h>
using namespace std;
const long long maxN = 10e6 + 5;
const long long oo = 1000000005;
string a[6] = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
string b[6] = {"ABACBC", "ABACCB", "ACBABC", "BABCCA", "ABCACB", "BACACB"};
string s[3];
void in() {
  for (int i = 0; i < 3; i++) {
    string temp;
    cin >> temp;
    if (temp[1] == '>') swap(temp[0], temp[2]);
    temp.erase(1, 1);
    s[i] = temp;
  }
  sort(s, s + 3);
}
void sol() {
  string t = "";
  for (int i = 0; i < 3; i++) t += s[i];
  for (int i = 0; i < 6; i++)
    if (t == b[i]) {
      cout << a[i] << endl;
      return;
    }
  cout << "Impossible";
}
int main() {
  in();
  sol();
  return 0;
}
