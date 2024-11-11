#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  char c, d;
  cin >> n >> m;
  string str;
  cin >> str;
  while (m--) {
    scanf("%d %d %c %c", &a, &b, &c, &d);
    replace(str.begin() + a - 1, str.end() - (n - b), c, d);
  }
  cout << str;
}
