#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s = "";
  int count = 0;
  for (int i = 0; i < n; i++) {
    s += static_cast<char>('a' + i % 26);
  }
  cout << s;
}
