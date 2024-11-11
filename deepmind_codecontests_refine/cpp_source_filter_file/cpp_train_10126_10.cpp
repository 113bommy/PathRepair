#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n, c = 0;
    cin >> n;
    string s;
    map<char, int> m;
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < s.length(); j++) {
        m[s[j]]++;
        c++;
      }
    }
    int k = 0;
    map<char, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
      if ((itr->second) % 2 != 0) {
        k = 1;
        break;
      }
    }
    if (k == 1 || c % n != 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
