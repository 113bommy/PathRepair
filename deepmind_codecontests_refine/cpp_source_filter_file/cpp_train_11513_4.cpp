#include <bits/stdc++.h>
using namespace std;
int main() {
  short n, k;
  cin >> n >> k;
  string password = "abcdefghijklmnopqrsvwxyz";
  string s, s1;
  for (short i = 0; i < k; i++) s += password[i];
  for (short i = 0; i < n; i++) s1 += s;
  for (short i = 0; i < n; i++) cout << s1[i];
  return 0;
}
