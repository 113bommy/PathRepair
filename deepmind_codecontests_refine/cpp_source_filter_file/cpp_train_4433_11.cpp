#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[101], b, c;
  string s;
  cin.tie();
  long min_ = 156544555;
  map<char, int> mp, mp1;
  while (cin >> n) {
    cin >> s;
    if (n % 4) {
      cout << "===\n";
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (isalpha(s[i])) {
        mp1[s[i]]++;
        if (mp[s[i]] > n / 4) {
          cout << "===\n";
          return 0;
        }
      }
    }
    mp['A'] = mp['G'] = mp['C'] = mp['T'] = n / 4;
    for (int i = 0; i < n; i++) {
      if (isalpha(s[i])) {
        mp[s[i]]--;
        cout << s[i];
      } else {
        if (mp1['A'] < n / 4) {
          cout << "A";
          mp1['A']++;
        } else if (mp1['G'] < n / 4) {
          cout << "G";
          mp1['G']++;
        } else if (mp1['C'] < n / 4) {
          cout << "C";
          mp1['C']++;
        } else if (mp1['T'] < n / 4) {
          cout << "T";
          mp1['T']++;
        }
      }
    }
  }
  return 0;
}
