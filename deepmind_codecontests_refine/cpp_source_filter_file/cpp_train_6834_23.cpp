#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  int temp;
  scanf("%d", &k);
  string ans = "";
  temp = k / 2;
  int i, j;
  if (temp <= 18) {
    for (i = 0; i < temp; i++) ans += "8";
    if (k % 2) ans += "4";
    cout << ans << endl;
  } else
    cout << "-1" << endl;
}
