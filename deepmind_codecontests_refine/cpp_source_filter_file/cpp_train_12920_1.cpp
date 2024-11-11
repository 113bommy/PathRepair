#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long begtime = clock();
  ;
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long low = 0, number = 0, upper = 0;
    for (auto c : s) {
      if (c - '0' >= 0 and c - '0' <= 9)
        number++;
      else if (c >= 'a' and c <= 'z')
        low++;
      else if (c >= 'A' and c <= 'Z')
        upper++;
    }
    if (low != 0 and number != 0 and upper != 0) {
      cout << s << endl;
    } else if (low == 0 and number == 0) {
      s[0] = '5', s[1] = 'p';
      cout << s << endl;
    } else if (low == 0 and upper == 0) {
      s[0] = '5', s[1] = 'P';
      cout << s << endl;
    } else if (upper == 0 and number == 0) {
      s[0] = 'P', s[1] = '5';
      cout << s << endl;
    } else if (upper == 0) {
      if (number >= 2) {
        for (long long i = 0; i < s.size(); i += 1) {
          if (s[i] >= '0' and s[i] <= '9') {
            s[i] = 'P';
            cout << s << endl;
            break;
          }
        }
      } else if (low >= 2) {
        for (long long i = 0; i < s.size(); i += 1) {
          if (s[i] >= 'a' and s[i] <= 'z') {
            s[i] = 'P';
            cout << s << endl;
            break;
          }
        }
      }
    } else if (low == 0) {
      if (number >= 2) {
        for (long long i = 0; i < s.size(); i += 1) {
          if (s[i] >= '0' and s[i] <= '9') {
            s[i] = 'p';
            cout << s << endl;
            break;
          }
        }
      } else if (upper >= 2) {
        for (long long i = 0; i < s.size(); i += 1) {
          if (s[i] >= 'A' and s[i] <= 'Z') {
            s[i] = 'p';
            cout << s << endl;
            break;
          }
        }
      }
    } else if (number == 0) {
      if (low >= 2) {
        for (long long i = 0; i < s.size(); i += 1) {
          if (s[i] >= 'a' and s[i] <= 'z') {
            s[i] = '5';
            cout << s << endl;
            break;
          }
        }
      } else if (upper >= 2) {
        for (long long i = 0; i < s.size(); i += 1) {
          if (s[i] >= 'A' and s[i] <= 'Z') {
            s[i] = '5';
            cout << s << endl;
            break;
          }
        }
      }
    }
  }
  long long endtime = clock();
  cerr << endl
       << "Time elapsed: " << (endtime - begtime) * 1000 / CLOCKS_PER_SEC
       << " ms";
  return 0;
}
