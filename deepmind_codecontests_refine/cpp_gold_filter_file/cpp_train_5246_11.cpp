#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, t = -1;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'R' && t == -1) {
      s = i + 1;
      t = i + 2;
    } else if (a[i] == 'R' && t != -1) {
      t++;
    }
    if (a[i] == 'L' && t == -1) {
      cout << i + 1 << " " << i;
      return 0;
    }
    if (a[i] == 'L' && t != -1) {
      cout << s << " " << i;
      return 0;
    }
  }
  cout << s << " " << t;
  return 0;
}
