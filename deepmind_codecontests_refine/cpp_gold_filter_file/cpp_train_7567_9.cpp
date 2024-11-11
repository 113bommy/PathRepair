#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int n;
  cin >> n >> str;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      reverse(str.begin(), str.begin() + (i));
    }
  }
  cout << str << endl;
  return 0;
}
