#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int temp[n + 2];
  int one = 0, two = 0;
  for (int i = 1; i <= n; i++) {
    cin >> temp[i];
    if (temp[i] == 1)
      one++;
    else
      two++;
  }
  int maxi = 0;
  for (int i = 1; i <= n; i++) {
    int one1 = 0, two1 = 0;
    for (int j = -110; j <= n; j++) {
      int c = (i + (j * k));
      if (c >= 1 && c <= n) {
        if (temp[c] == 1)
          one1++;
        else
          two1++;
      }
    }
    int ans = abs((one - one1) - (two - two1));
    if (maxi < ans) maxi = ans;
  }
  cout << maxi << endl;
  return 0;
}
