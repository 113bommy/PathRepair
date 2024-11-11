#include <bits/stdc++.h>
using namespace std;
string A[] = {"1x12", "2x6", "3x4", "4x3", "6x2", "12x1"};
vector<string> v;
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'X') {
        v.push_back(A[0]);
        break;
      }
    }
    for (int i = 1; i < 5; i++) {
      int idx1 = A[i][0] - '0';
      int idx2 = A[i][2] - '0';
      for (int j = 0; j < idx2; j++) {
        int flag = 0;
        for (int k = 0; k < idx1; k++) {
          if (s[idx2 * k + j] != 'X') {
            flag = 1;
          }
        }
        if (flag == 0) {
          v.push_back(A[i]);
          break;
        }
      }
    }
    if (s == "XXXXXXXXXXXX") {
      v.push_back(A[5]);
    }
    cout << v.size();
    for (int i = 0; i < v.size(); i++) {
      cout << " " << v[i];
    }
    cout << endl;
    v.clear();
  }
  return 0;
}
