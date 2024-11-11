#include <bits/stdc++.h>
using namespace std;
long long n, i, j, a[100500];
string s;
int main() {
  cin >> s;
  for (i = 0; i <= s.size() - 1; i++) {
    a[s[i]]++;
  }
  for (i >= 'a'; i <= 'z'; i++) {
    if (a[i] > 0) j++;
  }
  if (j % 2 == 0)
    cout << "CHAT WITH HER!";
  else
    cout << "IGNORE HIM!";
}
