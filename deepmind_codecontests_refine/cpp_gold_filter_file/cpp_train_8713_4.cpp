#include <bits/stdc++.h>
using namespace std;
int a[6];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[0] == 'p') {
      a[0] = 1;
    }
    if (s[0] == 'g') {
      a[1] = 1;
    }
    if (s[0] == 'b') {
      a[2] = 1;
    }
    if (s[0] == 'o') {
      a[3] = 1;
    }
    if (s[0] == 'r') {
      a[4] = 1;
    }
    if (s[0] == 'y') {
      a[5] = 1;
    }
  }
  int kol = 0;
  for (int i = 0; i < 6; i++) {
    if (a[i] == 0) {
      kol++;
    }
  }
  cout << kol << endl;
  if (a[0] == 0) cout << "Power" << endl;
  if (a[1] == 0) cout << "Time" << endl;
  if (a[2] == 0) cout << "Space" << endl;
  if (a[3] == 0) cout << "Soul" << endl;
  if (a[4] == 0) cout << "Reality" << endl;
  if (a[5] == 0) cout << "Mind" << endl;
}
