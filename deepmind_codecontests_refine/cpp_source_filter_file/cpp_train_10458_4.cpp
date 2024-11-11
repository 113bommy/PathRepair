#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[10] = {};
  for (int i = 0; i < 6; i++) cin >> a[i];
  sort(a, a + 6);
  for (int i = 0; i <= 2; i++) {
    bool ch = 0, ch2[10] = {};
    int o = 0, o2 = 0;
    for (int j = 1; j < i + 4; j++)
      if (a[i + j] != a[i]) ch = 1;
    for (int j = 0; j < i + 4; j++) ch2[i + j] = 1;
    for (int j = 0; j < 6; j++)
      if (!ch2[j])
        if (!o)
          o = a[j];
        else
          o2 = a[j];
    if (o2 > o && !ch) {
      cout << "Bear" << endl;
      return 0;
    }
    if (o2 == o && !ch) {
      cout << "Elephant" << endl;
      return 0;
    }
  }
  cout << "Alien" << endl;
  return 0;
}
