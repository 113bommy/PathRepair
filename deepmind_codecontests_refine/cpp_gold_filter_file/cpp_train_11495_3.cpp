#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, ans = 0, ans2 = 0, p;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> p;
    if (p == 25)
      ans++;
    else {
      if (p == 50) {
        ans2++, ans--;
      } else {
        ans--;
        if (ans2)
          ans2--;
        else
          ans -= 2;
      }
    }
    if (ans < 0 || ans2 < 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
