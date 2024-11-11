#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int len, l;
  string su;
  cin >> len;
  cin >> su;
  if (len == 1) {
    cout << su << endl;
  } else {
    for (int i = 1; i <= len - 1; i++) {
      if (su[i] < su[i - 1]) {
        l = i - 1;
        break;
      }
    }
  }
  for (int i = 0; i < len; i++) {
    if (i == l) {
    } else {
      cout << su[i];
    }
  }
}
