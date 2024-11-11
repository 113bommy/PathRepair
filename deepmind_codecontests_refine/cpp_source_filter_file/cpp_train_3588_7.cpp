#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, s3, s4;
  char c1, c2;
  cin >> s1 >> s2;
  int a, b, c, d, n, i, j, k, t;
  cin >> n;
  int num, m1[100] = {0}, m2[100] = {0};
  for (i = 0; i < n; i++) {
    cin >> t >> c1 >> num >> c2;
    if (c2 == 'r') {
      if (c1 == 'h' && (m1[num] == 0 || m1[num] == 1)) {
        cout << s1 << " " << num << " " << t << endl;
        m1[num] = 3;
      } else if (c2 == 'a' && m2[num] == 0 || m2[num] == 1) {
        cout << s2 << " " << num << " " << t << endl;
        m2[num] = 3;
      }
    }
    if (c2 == 'y') {
      if (c1 == 'h')
        m1[num]++;
      else if (c1 == 'a')
        m2[num]++;
      for (j = 1; j < 100; j++) {
        if (m1[j] == 2) {
          cout << s1 << " " << num << " " << t << endl;
          m1[j]++;
          break;
        } else if (m2[j] == 2) {
          cout << s2 << " " << num << " " << t << endl;
          m2[j]++;
          break;
        }
      }
    }
  }
  return 0;
}
