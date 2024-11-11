#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5], kq = 3, dif = 0;
  for (int i = 1; i <= 4; i++) cin >> a[i];
  for (int i = 1; i <= 3; i++) {
    int count = 0;
    for (int j = i + 1; j <= 4; j++) {
      if (a[i] == a[j])
        count++;
      else
        dif++;
    }
    if (count == 0) --kq;
  }
  if (dif == 0)
    cout << 3;
  else
    cout << kq;
}
