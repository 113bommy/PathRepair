#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n) {
    cin >> s1;
    cin >> s2;
    int a = 0, b = 0, c = 0, d = 0;
    vector<int> v1, v2, v3, v4;
    for (int i = 0; i < n; i++)
      if (s1[i] == '0' && s2[i] == '0')
        a++, v1.push_back(i + 1);
      else if (s1[i] == '0' && s2[i] == '1')
        b++, v2.push_back(i + 1);
      else if (s1[i] == '1' && s2[i] == '0')
        c++, v3.push_back(i + 1);
      else
        d++, v4.push_back(i + 1);
    bool flag = 0;
    for (int p1 = 0; p1 <= a; p1++) {
      for (int p2 = 0; p2 <= b; p2++) {
        int p3 = n + p2 - 2 * (p1 + p2) - b - d;
        if (p3 >= 0 && p3 <= c) {
          int p4 = n / 2 - p1 - p2 - p3;
          if (p4 >= 0 && p4 <= d) {
            flag = 1;
            for (int i = 0; i < p1; i++) cout << v1[i] << ' ';
            for (int i = 0; i < p2; i++) cout << v2[i] << ' ';
            for (int i = 0; i < p3; i++) cout << v3[i] << ' ';
            for (int i = 0; i < p4; i++) cout << v4[i] << ' ';
            cout << endl;
          }
        }
        if (flag) break;
      }
      if (flag) break;
    }
    if (!flag) cout << -1 << endl;
  }
  return 0;
}
