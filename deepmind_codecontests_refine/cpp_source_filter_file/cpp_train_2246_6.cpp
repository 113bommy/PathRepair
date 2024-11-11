#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a;
  cin >> b;
  long long ci = stoi(a) + stoi(b);
  string c = to_string(ci);
  string a1 = "", b1 = "", c1 = "";
  for (int i = 0; i < a.length(); i++) {
    if (i != '0') {
      a1 += a[i];
    }
  }
  for (int i = 0; i < b.length(); i++) {
    if (i != '0') {
      b1 += b[i];
    }
  }
  for (int i = 0; i < c.length(); i++) {
    if (i != '0') {
      c1 += c[i];
    }
  }
  int c1i = stoi(a1) + stoi(b1);
  if (c1i == stoi(c1))
    cout << "YES\n";
  else
    cout << "NO\n";
}
