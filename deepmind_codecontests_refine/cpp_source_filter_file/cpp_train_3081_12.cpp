#include <bits/stdc++.h>
using namespace std;
string s;
int a, b = 10;
signed main() {
  for (int i = 0; i < 8; i++) {
    int sum = 0;
    cin >> s;
    for (int j = 0; j < 8; j++) {
      if (s[j] == 'B') sum++;
    }
    if (!sum) a++;
    b = min(b, sum);
  }
  if (a == 8)
    return printf("8\n"), 0;
  else
    return printf("%d\n", a + b), 0;
}
