#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000000 + 7;
int addm(int& a, int b) { return (a += b) < mod ? a : a -= mod; }
template <class T, class U>
bool smin(T& a, U b) {
  return a > b ? (a = b, 1) : 0;
}
template <class T, class U>
bool smax(T& a, U b) {
  return a < b ? (a = b, 1) : 0;
}
int n, a, b, k;
string s;
bool bd[200001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b >> k;
  cin >> s;
  int l = 0;
  for (int i = n; i >= 0; i--, l++) {
    if (s[i] == '1') l = 0;
    if (l < b) bd[i] = 1;
  }
  int numpos = 0;
  int ct = 0;
  for (int i = 0; i <= n; i++) {
    if (bd[i]) {
      numpos += (ct + b - 1) / b;
      ct = 0;
    } else
      ct++;
  }
  vector<int> tohit;
  l = 0;
  for (int i = n; i >= 0 && numpos >= a; i--) {
    if (bd[i] == 0 && l >= b) {
      numpos--;
      tohit.push_back(i + 1);
      l = 1;
    } else
      l++;
  }
  cout << tohit.size() << endl;
  for (int& a : tohit) cout << a << ' ';
  cout << endl;
}
