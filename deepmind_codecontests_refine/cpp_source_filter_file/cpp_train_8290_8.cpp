#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, a[10], s[10];
  int i, j, n = 10;
  getline(cin, str);
  for (i = 0; i < n; i++) getline(cin, a[i]);
  for (i = 0; i < n; i++) s[i] = str.substr(i * 8, 8);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (s[i] == a[j]) cout << j;
  cout << endl;
  return 0;
}
