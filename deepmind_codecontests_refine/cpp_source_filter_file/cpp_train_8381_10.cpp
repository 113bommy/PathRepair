#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int temp = a[i];
    if (i == 0) {
      if (temp % 4 == 0) {
        ans++;
      }
    }
    if (i != 0) {
      char str[3];
      int pos = 0;
      if (temp % 2 == 0) {
        if (temp % 4 == 0) {
          ans++;
        }
        str[pos] = a[i - 1];
        str[pos + 1] = a[i];
        str[pos + 2] = '\0';
        temp = stoi(str);
        if (temp % 4 == 0) {
          ans += (i);
        }
      }
    }
  }
  cout << ans;
}
