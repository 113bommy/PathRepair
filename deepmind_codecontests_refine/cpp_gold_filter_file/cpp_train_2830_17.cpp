#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 == s2) {
    cout << 0;
  } else {
    long long cnt1 = 0, cnt2 = 0;
    for (long long i = 0; i < n; i++) {
      if (s1[i] == 'a') {
        cnt1++;
      } else {
        cnt2++;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (s2[i] == 'a') {
        cnt1++;
      } else {
        cnt2++;
      }
    }
    if ((cnt1 % 2) || (cnt2 % 2)) {
      cout << -1 << endl;
    } else {
      vector<long long> rt1;
      vector<long long> rt2;
      for (long long i = 0; i < n; i++) {
        if ((s1[i] == 'a') && (s2[i] == 'b')) {
          rt1.push_back(i + 1);
        } else if ((s1[i] == 'b') && (s2[i] == 'a')) {
          rt2.push_back(i + 1);
        }
      }
      if (rt1.size() % 2) {
        cout << (rt1.size() / 2 + rt2.size() / 2) + 2 << endl;
        for (long long i = 0; i < rt1.size() - 1; i = i + 2) {
          cout << rt1[i] << " " << rt1[i + 1];
          cout << endl;
        }
        for (long long i = 0; i < rt2.size() - 1; i = i + 2) {
          cout << rt2[i] << " " << rt2[i + 1];
          cout << endl;
        }
        cout << rt1[rt1.size() - 1] << " " << rt1[rt1.size() - 1] << endl;
        cout << rt1[rt1.size() - 1] << " " << rt2[rt2.size() - 1] << endl;
      } else {
        cout << rt1.size() / 2 + rt2.size() / 2 << endl;
        for (long long i = 0; i < rt1.size(); i = i + 2) {
          cout << rt1[i] << " " << rt1[i + 1];
          cout << endl;
        }
        for (long long i = 0; i < rt2.size(); i = i + 2) {
          cout << rt2[i] << " " << rt2[i + 1];
          cout << endl;
        }
      }
    }
  }
  return 0;
}
