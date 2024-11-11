#include <bits/stdc++.h>
using namespace std;
int main() {
  int v = 0, s = 0;
  long long n;
  cin >> n;
  string str = to_string(n);
  for (char i : str) {
    int t = i - '0';
    if (t == 4) v++;
    if (t == 7) s++;
  }
  int su = v + s;
  cout << ((su == 4 || su == 7) ? "YES" : "NO");
  return 0;
}
