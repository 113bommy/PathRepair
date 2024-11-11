#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    int flag = 1;
    for (i = 2; i <= str1.length() - 2; i++) {
      if (str1[i] == '1' && str2[i] == '1') {
        flag = 0;
        break;
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
