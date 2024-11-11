#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i <= n - 11; i++) {
    if (s[i] == '8') {
      sum++;
    }
  }
  if (sum > (n - 11) / 2) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
