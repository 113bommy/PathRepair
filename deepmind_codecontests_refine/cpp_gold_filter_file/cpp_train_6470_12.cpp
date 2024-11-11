#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1001;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = (s.length() - 11) / 2;
  int cnt8 = 0;
  for (int i = 0; i < s.length() - 10; i++)
    if (s[i] == '8') cnt8++;
  if (cnt8 > count)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
