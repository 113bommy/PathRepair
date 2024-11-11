#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c[n], count[n], answer[n], i, j, x;
  for (i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (i = 0; i <= n; i++) {
    answer[i] = 0;
  }
  for (j = 1; j <= n; j++) {
    int andy = 0;
    for (i = 0; i <= n; i++) {
      count[i] = 0;
    }
    for (i = j; i <= n; i++) {
      x = c[i];
      count[x]++;
      if (count[x] > count[andy] || (count[x] == count[andy] && x < andy))
        andy = x;
      answer[andy]++;
    }
  }
  for (i = 1; i <= n; i++) {
    cout << answer[i] << " ";
  }
}
