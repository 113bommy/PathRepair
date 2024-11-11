#include <bits/stdc++.h>
using namespace std;
string str;
void solve() {
  int count = 1;
  char c = 'a';
  for (int i = 0; i < (int)str.size(); i++)
    if (str[i] > c) {
      count = 1;
      c = str[i];
    } else if (str[i] == c)
      count++;
  for (int i = 1; i <= count; i++) cout << c;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> str;
  solve();
  return 0;
}
