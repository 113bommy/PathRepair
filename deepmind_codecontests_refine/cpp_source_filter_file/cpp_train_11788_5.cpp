#include <bits/stdc++.h>
char str[105];
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    scanf("%s", str);
    int n = strlen(str);
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++)
      if (str[i] == '1') {
        p1 = i;
        break;
      }
    for (int i = n - 1; i >= 0; i--)
      if (str[i] == '1') {
        p2 = i;
        break;
      }
    int cnt = 0;
    for (int i = p1; i <= p2; i++)
      if (str[i] == '0') cnt++;
    if (p1 == 0) cnt = 0;
    std::cout << cnt << std::endl;
  }
}
