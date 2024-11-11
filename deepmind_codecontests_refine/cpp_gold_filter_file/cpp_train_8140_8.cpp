#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<long long> a;
    long long n = s.length();
    for (long long i = 0; i < n;) {
      if (i + 5 <= n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' &&
          s[i + 3] == 'n' && s[i + 4] == 'e') {
        a.push_back(i + 2);
        i = i + 5;
      } else if (i + 2 < n && s[i] == 't' && s[i + 1] == 'w' &&
                 s[i + 2] == 'o') {
        a.push_back(i + 1);
        i = i + 3;
      } else if (i + 2 < n && s[i] == 'o' && s[i + 1] == 'n' &&
                 s[i + 2] == 'e') {
        a.push_back(i + 1);
        i = i + 3;
      } else
        i++;
    }
    cout << a.size() << "\n";
    for (auto i : a) cout << i + 1 << " ";
    cout << "\n";
  }
}
