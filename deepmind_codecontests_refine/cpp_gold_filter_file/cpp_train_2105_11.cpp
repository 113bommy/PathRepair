#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  int a = 0, b = 0;
  cin >> n >> s;
  for (auto &it : s) {
    if (it == 'L')
      ++a;
    else
      ++b;
  }
  cout << a + b + 1;
  return 0;
}
