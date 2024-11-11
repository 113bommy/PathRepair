#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  bool res = false;
  while (n--) {
    string str;
    int b, a;
    cin >> str >> b >> a;
    res = res || (b >= 2400 && a > b);
  }
  cout << (res ? "YES" : "NO");
  return 0;
}
