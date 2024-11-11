#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k;
string s;
string a[501];
int main() {
  cin >> s;
  cin >> m;
  for (i = 0; i < s.size(); i++)
    if (s[i] >= 'a' && s[i] - 'a' < m)
      s[i] = s[i] - 'a' + 'A';
    else if (s[i] <= 'Z' && s[i] - 'A' >= m)
      s[i] = s[i] - 'A' + 'a';
  cout << s << endl;
}
