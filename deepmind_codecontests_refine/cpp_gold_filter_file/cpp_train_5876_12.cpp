#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  if (a.length() != b.length()) goto no;
  for (int i = 0, j = a.length() - 1; i < a.length(); i++, j--)
    if (a[i] != b[j]) goto no;
  cout << "YES\n";
  return 0;
no:;
  cout << "NO\n";
  return 0;
}
