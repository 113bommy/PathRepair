#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5];
  for (int i = 0; i < 4; i++) cin >> a[i];
  sort(a, a + 4);
  int flag = 0;
  int ans1 = 0, ans2 = 0;
  for (int i = 3; i >= 0; i--) {
    if (ans1 >= ans2)
      ans2 += a[i];
    else {
      ans1 += a[i];
    }
  }
  if (ans1 == ans2)
    flag = 0;
  else
    flag = 1;
  if (flag) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
