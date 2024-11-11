#include <bits/stdc++.h>
using namespace std;
void run() {
  int n, p, q;
  string s;
  cin >> n >> p >> q;
  cin >> s;
  int dem = 0;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s.size() == i * p + j * q) {
        x = i;
        y = j;
        dem++;
      }
  if (x + y != 0) cout << x + y << endl;
  if (x != 0 || y != 0) {
    int kt = 0, d = 0;
    int i = 0, j;
    if (x != 0) {
      for (i = 0; i < s.size(); i++) {
        if (d == p) {
          cout << endl;
          i--;
          kt++;
          d = 0;
        } else {
          cout << s[i];
          d++;
        }
        if (kt == x) break;
      }
      kt = 0, d = 0;
      for (j = i + 1; j < s.size(); j++) {
        if (d == q) {
          cout << endl;
          j--;
          kt++;
          d = 0;
        } else {
          cout << s[j];
          d++;
        }
        if (kt == y) {
          break;
        }
      }
    } else {
      kt = 0, d = 0;
      for (j = 0; j < s.size(); j++) {
        if (d == q) {
          cout << endl;
          j--;
          kt++;
          d = 0;
        } else {
          cout << s[j];
          d++;
        }
        if (kt == y) {
          break;
        }
      }
    }
  } else {
    cout << "-1";
  }
}
int main() {
  run();
  return 0;
}
