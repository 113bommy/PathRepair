#include <bits/stdc++.h>
using namespace std;
const int maxn = -1;
const int inf = 1e9;
int f(char ch) {
  if (ch == '(') return 3;
  if (ch == '[') return 2;
  if (ch == '8') return 1;
  assert(false);
}
int main() {
  int a, b;
  cin >> a >> b;
  cout << b + a << endl;
  return 0;
}
