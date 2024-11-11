#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  cout << (s[0]=='M'?6:(s[0]=='W'?4:(s[0]=='F'?2:(s[2]=='N'?7:(s[2]=='T'?1:(s[2]=='E'?5:3)))))) << endl;
}
