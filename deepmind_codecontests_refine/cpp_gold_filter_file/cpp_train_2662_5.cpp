#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n, a, b;
  string str;
  cin >> n >> a >> b;
  cin >> str;
  if (str[a - 1] != str[b - 1]) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
