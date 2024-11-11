#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, ans;
  scanf("%d", &a);
  ans = 1;
  for (int i = 1; i <= a; i++) {
    if (i * i >= a) {
      ans = i;
      break;
    }
  }
  if (ans * ans == a) {
    cout << 2 * (ans + ans) << endl;
  } else {
    int p = ans - 1;
    if (ans * p < a)
      cout << 2 * (ans + ans) << endl;
    else
      cout << 2 * (ans + p) << endl;
  }
}
