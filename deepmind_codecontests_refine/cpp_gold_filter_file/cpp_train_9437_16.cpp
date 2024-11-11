#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  vector<int> countq(26, 0);
  int i;
  for (i = 0; i < x.size(); i++) {
    countq[x[i] - 'a']++;
  }
  int diff = 0;
  int a = -1, b = -1, c = -1;
  for (i = 0; i < 26; i++) {
    if (countq[i] != 0) {
      diff++;
      if (a == -1) {
        a = i;
        continue;
      }
      if (a != -1 && b == -1) {
        b = i;
        continue;
      }
      if (a != -1 && b != -1 && c == -1) {
        c = i;
        continue;
      }
    }
  }
  if (diff > 4) {
    cout << "NO" << endl;
  } else {
    if (diff == 4) {
      cout << "YES" << endl;
    } else if (diff == 3) {
      if (countq[a] > 1 || countq[b] > 1 || countq[c] > 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (diff == 2) {
      if (countq[a] > 1 && countq[b] > 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
