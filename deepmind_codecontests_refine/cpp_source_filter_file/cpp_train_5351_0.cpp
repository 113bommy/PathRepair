#include <bits/stdc++.h>
using namespace std;
string tostring(long long n) {
  ostringstream ss;
  ss << n;
  return ss.str();
}
long long tonumber(string str) {
  stringstream ss;
  ss << str;
  long long n;
  ss >> n;
  return n;
}
char arr[10][10];
int main() {
  int r, c, ccounter = 0, rcounter = 0;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    bool flag = 0;
    for (int j = 0; j < c; j++) {
      char x;
      cin >> x;
      if (x == 'S') flag = 1;
      arr[i][j] = x;
    }
    if (flag == 0) rcounter++;
  }
  for (int i = 0; i < c; i++) {
    bool flag = 0;
    for (int j = 0; j < r; j++) {
      if (arr[i][j] == 'S') flag = 1;
    }
    if (flag == 0) ccounter++;
  }
  int val = r - rcounter, mx = (rcounter * c) + (val * ccounter);
  cout << mx << endl;
  return 0;
}
