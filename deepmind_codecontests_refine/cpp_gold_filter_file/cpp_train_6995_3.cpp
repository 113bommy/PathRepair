#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[16] = {0};
  int index = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    bool lucky = true;
    for (int j = 0; j < (s.length()); j++) {
      if (s[j] != '4' && s[j] != '7') {
        lucky = false;
        break;
      }
    }
    if (lucky) {
      a[index] = i;
      index++;
    }
  }
  for (int i = 0; i < 16; i++) {
    if (a[i] != 0) {
      if (n % a[i] == 0) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
