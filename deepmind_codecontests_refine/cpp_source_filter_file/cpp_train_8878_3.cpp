#include <bits/stdc++.h>
using namespace std;
string mask(int a) {
  string ans;
  int x = a;
  while (x) {
    if (x % 10 == 4 || x % 10 == 7) ans.insert(ans.begin(), x % 10 + '0');
    x /= 10;
  }
  return ans;
}
int main() {
  string b;
  int a;
  cin >> a >> b;
  while (mask(a) != b) a++;
  cout << a;
}
