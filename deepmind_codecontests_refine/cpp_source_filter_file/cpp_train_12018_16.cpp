#include <bits/stdc++.h>
using namespace std;
int toI(string S) {
  stringstream ss;
  ss << S;
  int n;
  ss >> n;
  return n;
}
string toS(int n) {
  stringstream ss;
  ss << n;
  string S;
  ss >> S;
  return S;
}
int st[100001];
int en[100001];
int main() {
  int n, a, b, flg = 1;
  cin >> n;
  memset(st, 0, sizeof(st)), memset(en, 0, sizeof(en));
  while (n--) {
    cin >> b >> a;
    if (st[a] <= b && en[a] >= b)
      ;
    else if (en[a] + 1 == b)
      en[a]++;
    else
      flg = 0;
  }
  if (flg)
    cout << "YES";
  else
    cout << "NO";
}
