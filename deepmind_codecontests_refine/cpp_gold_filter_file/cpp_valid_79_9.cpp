#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    unordered_map<char, int> ourmap, ourmap1;
    int flag = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
          s[i] == '9') {
        flag = s[i] - '0';
        break;
      } else {
        ourmap[s[i]]++;
        if (ourmap[s[i]] == 1) ourmap1[s[i]] = i + 1;
      }
    }
    if (flag != 0) {
      cout << "1\n";
      cout << flag << "\n";
      continue;
    }
    cout << "2\n";
    if (ourmap.count('2') > 0 && ourmap['2'] > 1) {
      cout << "22\n";
    } else if (ourmap.count('3') > 0 && ourmap['3'] > 1) {
      cout << "33\n";
    } else if (ourmap.count('5') > 0 && ourmap['5'] > 1) {
      cout << "55\n";
    } else if (ourmap.count('7') > 0 && ourmap['7'] > 1) {
      cout << "77\n";
    } else if (ourmap.count('5') > 0 && ourmap.count('2') > 0) {
      if (ourmap1['5'] < ourmap1['2'])
        cout << "52\n";
      else
        cout << "25\n";
    } else if (ourmap.count('5') > 0 && ourmap.count('7') > 0) {
      if (ourmap1['5'] < ourmap1['7'])
        cout << "57\n";
      else
        cout << "75\n";
    } else if (ourmap.count('2') > 0 && ourmap.count('7') > 0) {
      if (ourmap1['2'] < ourmap1['7'])
        cout << "27\n";
      else
        cout << "72\n";
    } else if (ourmap.count('5') > 0 && ourmap.count('3') > 0 &&
               ourmap1['3'] < ourmap1['5']) {
      cout << "35\n";
    } else {
      cout << "32\n";
    }
  }
}
