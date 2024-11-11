#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
string s;
int main() {
  int n;
  scanf("%d", &n);
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < int(s.length()); i++) {
    if ((s[i] == 'C' && s[i + 1] == 'C') || (s[i] == 'Y' && s[i + 1] == 'Y') ||
        (s[i] == 'M' && s[i + 1] == 'M')) {
      cout << "No" << endl;
      return 0;
    }
    if ((s[i - 1] == 'M' && s[i] == '?' && s[i + 1] == 'C') ||
        (s[i - 1] == 'M' && s[i] == '?' && s[i + 1] == 'Y') ||
        s[i - 1] == 'Y' && s[i] == '?' && s[i + 1] == 'C' ||
        s[i - 1] == 'Y' && s[i] == '?' && s[i + 1] == 'M' ||
        s[i - 1] == 'C' && s[i] == '?' && s[i + 1] == 'M' ||
        s[i - 1] == 'C' && s[i] == '?' && s[i + 1] == 'Y')
      continue;
    if (s[i] == '?') cnt++;
  }
  if (cnt > 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
