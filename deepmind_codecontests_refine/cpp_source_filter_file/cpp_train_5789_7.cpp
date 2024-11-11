#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long toint(string s) {
  long long a = 0, c = 1;
  ;
  for (int i = 0; i < s.size(); i++) {
    a += (s[s.size() - i - 1] - '0') * c;
    c *= 10;
  }
  return a;
}
string binary(int x) {
  string num = "";
  while (x != 0) {
    num += x % 2 + '0';
    x /= 2;
  }
  return num;
}
long long decimal(string x) {
  long long a = 1;
  long long u = 0;
  for (long long i = 0; i < x.size(); i++) {
    if (x[i] == '1') u += a;
    a *= 2;
  }
  return u;
}
int brr[1000000];
int main() {
  fast();
  int arr[5][5], a = 0;
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++) cin >> arr[i][j];
  if (arr[1][4])
    if (arr[1][1] || arr[1][3] || arr[1][2] || arr[2][1] || arr[3][2] ||
        arr[4][3])
      a = 1;
  if (arr[2][4]) {
    if (arr[2][1] || arr[2][3] || arr[2][2] || arr[1][3] || arr[3][1] ||
        arr[4][2])
      a = 1;
  }
  if (arr[3][4]) {
    if (arr[3][1] || arr[3][3] || arr[3][2] || arr[4][1] || arr[2][3] ||
        arr[1][2])
      a = 1;
  }
  if (arr[4][4]) {
    if (arr[4][1] || arr[4][3] || arr[4][2] || arr[1][4] || arr[3][3] ||
        arr[2][2])
      a = 1;
  }
  if (a)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
