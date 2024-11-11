#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  cin >> n;
  int k = n / 4;
  for (int i = 0; i < k; i += 4) s += "abcd";
  for (int i = 0; i < n % 4; i++) s += 'a' + i;
  cout << s;
  return 0;
}
