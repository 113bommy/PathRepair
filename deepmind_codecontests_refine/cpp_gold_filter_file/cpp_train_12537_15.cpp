#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  char c[n];
  int amt = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  if (c[0] == '.') {
    int curr;
    for (int i = 0; i < n; i++) {
      if (c[i] == 'L') {
        curr = i;
        break;
      } else if (c[i] == 'R') {
        amt = amt + (i);
        curr = i;
        break;
      }
    }
    int t = 0;
    int cnt1 = 0;
    int cnt = 0;
    for (int i = curr; i < n; i++) {
      if (c[i] == 'L' && t == 0)
        ;
      else if (c[i] == 'R') {
        t = 1;
        amt = amt + cnt1;
        cnt1 = 0;
      } else if (c[i] == 'L' && t == 1) {
        if (cnt % 2 == 1) amt++;
        t = 0;
        cnt = 0;
      } else if (c[i] == '.' && t == 1) {
        cnt++;
      } else if (c[i] == '.' && t == 0) {
        cnt1++;
      }
    }
    amt = amt + cnt1;
    cout << amt << endl;
  } else {
    int t = 0;
    int cnt1 = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] == 'L' && t == 0)
        ;
      else if (c[i] == 'R') {
        t = 1;
        amt = amt + cnt1;
        cnt1 = 0;
      } else if (c[i] == 'L' && t == 1) {
        if (cnt % 2 == 1) amt++;
        t = 0;
        cnt = 0;
      } else if (c[i] == '.' && t == 1) {
        cnt++;
      } else if (c[i] == '.' && t == 0) {
        cnt1++;
      }
    }
    amt = amt + cnt1;
    cout << amt << endl;
  }
}
