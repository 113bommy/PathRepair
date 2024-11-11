#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> odd;
    vector<int> eve;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      char c = s[i];
      int val = c - '0';
      if (val % 2) {
        odd.push_back(val);
      } else {
        eve.push_back(val);
      }
    }
    int i = 0, j = 0;
    int eve_n = eve.size();
    int odd_n = odd.size();
    string out = "";
    while (i < eve_n && j < odd_n) {
      if (eve[i] < odd[i]) {
        out += eve[i] + '0';
        i++;
      } else {
        out += odd[j] + '0';
        j++;
      }
    }
    while (i < eve_n) {
      out += eve[i] + '0';
      i++;
    }
    while (j < odd_n) {
      out += odd[j] + '0';
      j++;
    }
    cout << out << "\n";
  }
  return 0;
}
