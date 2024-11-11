#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    vector<int> holes;
    string s;
    cin >> s;
    int currcnt;
    if (s[0] == '.')
      currcnt = 1;
    else
      currcnt = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '.')
        currcnt++;
      else {
        if (currcnt > 0) holes.push_back(currcnt);
        currcnt = 0;
      }
    }
    if (currcnt > 0) holes.push_back(currcnt);
    if (a >= 2 * b) {
      int agood = 0;
      int bgood = 0;
      for (int i = 0; i < holes.size(); i++) {
        if (holes[i] >= b) bgood++;
        if (holes[i] >= a && holes[i] <= a + 2 * (b - 1)) agood++;
      }
      if (agood == 1 && bgood == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      int gt2b = 0;
      int b_x_a = 0;
      int pos = -1;
      for (int i = 0; i < holes.size(); i++) {
        if (holes[i] >= b && holes[i] < a) b_x_a++;
        if (holes[i] >= 2 * b) {
          pos = i;
          gt2b++;
        }
      }
      if (gt2b >= 2 || b_x_a >= 1) {
        cout << "NO" << endl;
        continue;
      }
      int cntr = 0;
      for (int i = 0; i < holes.size(); i++)
        if (holes[i] >= a && holes[i] < 2 * b) cntr++;
      if (gt2b == 0) {
        if (cntr % 2 == 0)
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
      } else {
        int num = holes[pos];
        bool pos1 = (cntr % 2 == 0) && (num >= 3 * a) && (num <= a + 4 * b - 2);
        bool pos2 = (cntr % 2 == 1) && (num >= 2 * a) && (num <= a + 2 * b - 1);
        bool pos3 = (cntr % 2 == 0) && (num >= a && num <= a + 2 * b - 2);
        bool pos4 = (cntr % 2 == 1) && (num >= 2 * a) && (num <= a + 3 * b - 2);
        if (pos1 || pos2 || pos3 || pos4)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    }
  }
}
