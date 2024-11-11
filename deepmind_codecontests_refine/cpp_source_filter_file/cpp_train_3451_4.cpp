#include <bits/stdc++.h>
using namespace std;
bool chk(long long x) {
  while (x != 0) {
    if (!(x & 1)) {
      return 0;
    }
    x = x >> 1;
  }
  return 1;
}
vector<int> ans;
int main() {
  long long int x;
  cin >> x;
  int turn = 0;
  if (chk(x)) {
    cout << "0\b";
    return 0;
  }
  while (1) {
    turn++;
    int t = 0;
    long long _xor = 0;
    if (turn % 2 == 1) {
      long long tmp = x;
      while (tmp & 1) {
        tmp = tmp >> 1;
        _xor = _xor << 1;
        t++;
        _xor = _xor | 1;
      }
      while (!(tmp & 1)) {
        tmp = tmp >> 1;
        _xor = _xor << 1;
        t++;
        _xor = _xor | 1;
      }
      x = x ^ _xor;
      ans.push_back(t);
    } else
      x = x + 1;
    if (chk(x)) break;
  }
  cout << turn << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
