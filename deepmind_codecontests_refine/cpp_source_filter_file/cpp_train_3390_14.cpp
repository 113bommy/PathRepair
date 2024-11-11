#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum1 = 0, m, sum2 = 0;
  char a;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < m; j++) {
      cin >> a;
      if (a == 'W' || a == 'G' || a == 'B')
        sum1++;
      else
        sum2++;
    }
  }
  if (sum2 > 0) {
    cout << "#Color";
  } else
    cout << "#Black&White";
}
