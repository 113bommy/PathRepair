#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int c1 = 0;
    if (s.size() == 1) {
      cout << s[0] << "\n";
      continue;
    }
    map<int, int> mp;
    string s1 = s;
    sort(s1.begin(), s1.end());
    for (int i = 0; i < n; i++) {
      mp[s[i]]++;
    }
    if (s[0] == '0' && s[n - 1] == '0') {
      if (mp['1'] > 0) {
        int c = 0;
        string s2 = "";
        while (s[c] != '1') {
          c++;
          s2 += '0';
        }
        cout << s2 + '0' << "\n";
      } else
        cout << s << "\n";
    } else if (s[0] == '0' && s[n - 1] == '1') {
      if (s.compare(s1) == 0) {
        cout << s << "\n";
      } else {
        int c = 0;
        string s2 = "";
        while (s[c] != '1') {
          c++;
          s2 += '0';
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
          if (s[i] == '0') {
            j = i;
          }
        }
        string s3 = "";
        j = n - 1 - j;
        while (j--) {
          s3 += '1';
        }
        cout << s2 + "0" + s3 << "\n";
      }
    } else if (s[0] == '1' && s[n - 1] == '0') {
      cout << '0' << "\n";
    } else if (s[0] == '1' && s[n - 1] == '1') {
      int j = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          j = i;
        }
      }
      string s3 = "";
      j = n - 1 - j;
      while (j--) {
        s3 += '1';
      }
      if (mp['0'] > 0) {
        cout << "0" + s3 << "\n";
      } else {
        cout << s << "\n";
      }
    }
  }
  return 0;
}
