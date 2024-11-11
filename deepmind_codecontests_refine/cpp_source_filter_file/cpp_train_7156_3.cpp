#include <bits/stdc++.h>
using namespace std;
const long long maxc = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  if (s.size() < 3) {
    cout << "No" << endl;
    return 0;
  }
  for (long long i = 1; i < s.size() - 1; i++) {
    if (s[i] == 'A' && s[i - 1] == 'B' && s[i + 1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] == 'A' && s[i - 1] == 'B' && s[i + 1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] == 'B' && s[i - 1] == 'A' && s[i + 1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] == 'B' && s[i - 1] == 'C' && s[i + 1] == 'A') {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] == 'C' && s[i - 1] == 'A' && s[i + 1] == 'B') {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] == 'C' && s[i - 1] == 'B' && s[i + 1] == 'A') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
