#include <bits/stdc++.h>
using namespace std;
int program(int x, vector<char> &op, vector<int> &a) {
  int n = op.size();
  for (int i = 0; i < n; i++) {
    if (op[i] == '&')
      x &= a[i];
    else if (op[i] == '^')
      x ^= a[i];
    else
      x |= a[i];
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  int n;
  cin >> n;
  vector<char> op(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> op[i] >> a[i];
  int andnum = 1023;
  int ornum = 0, xornum = 0;
  for (int i = 0; i < 10; i++) {
    int x = 1 << i;
    int y1 = program(x, op, a) & x;
    int y0 = program(0, op, a) & x;
    if (y0 == 0 and y1 == 0) andnum &= (1023 - x);
    if (y0 == 1 and y1 == 1) ornum |= x;
    if (y0 == 1 and y1 == 0) xornum |= x;
  }
  cout << 3 << endl;
  cout << "& " << andnum << endl;
  cout << "^ " << xornum << endl;
  cout << "| " << ornum << endl;
  return 0;
}
