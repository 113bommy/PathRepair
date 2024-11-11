#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool f = 0;
  while (n--) {
    string s;
    int a, b;
    cin >> s >> a >> b;
    if (a >= 2400 && b > a) f = 1;
  }
  cout << (f ? "YES" : "NO");
}
