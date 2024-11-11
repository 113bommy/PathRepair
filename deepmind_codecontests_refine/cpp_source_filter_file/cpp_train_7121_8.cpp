#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n], cnt_5 = 0, cnt_0 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      cnt_0++;
    } else
      cnt_5++;
  }
  if (!cnt_0) {
    cout << "-1";
    return 0;
  }
  int five = cnt_5 / 3 * 3;
  for (int i = 0; i < five; i++) {
    cout << "5";
  }
  if (five != 0) {
    for (int i = 0; i < cnt_0; i++) cout << "0";
  } else
    printf("0");
  return 0;
}
