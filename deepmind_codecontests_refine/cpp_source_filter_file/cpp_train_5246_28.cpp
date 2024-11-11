#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d ", &n);
  string ss;
  cin >> ss;
  int cnt1 = 0, cnt2 = 0, cnt0 = 0;
  for (int i = 0; i < ss.size(); i++) {
    if (ss[i] == 'R') cnt1++;
    if (ss[i] == 'L') cnt2++;
    if (ss[i] == '.') cnt0++;
  }
  if (cnt1 == ss.size() - cnt0) {
    int s = -1, e = -1;
    for (int i = 0; i < ss.size(); i++) {
      if (ss[i] == 'R') {
        if (s == -1) s = i + 1;
        e = i + 2;
      }
    }
    return cout << s << " " << e << endl, 0;
  } else if (cnt2 == ss.size() - cnt0) {
    int s = -1, e = -1;
    for (int i = 0; i < ss.size(); i++) {
      if (ss[i] == 'L') {
        if (e == -1) e = i;
        s = i + 2;
      }
    }
    return cout << s << " " << e << endl, 0;
  } else {
    int s = -1, e = -1;
    for (int i = 0; i < ss.size(); i++) {
      if (ss[i] == 'R' && s == -1) s = i + 1;
      if (ss[i] == 'L') {
        e = i;
        break;
      }
    }
    return cout << s << " " << e << endl, 0;
  }
  return 0;
}
