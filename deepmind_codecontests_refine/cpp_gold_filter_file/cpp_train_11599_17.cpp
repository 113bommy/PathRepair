#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  cin >> str;
  long long i = str.length() - 1;
  while (i >= 0) {
    if (str[i] == '1') {
      i--;
      continue;
    }
    if (i - 1 >= 0 && str[i] == '4' && str[i - 1] == '1') {
      i = i - 2;
      continue;
    }
    if (i - 2 >= 0 && str[i] == '4' && str[i - 1] == '4' && str[i - 2] == '1') {
      i = i - 3;
      continue;
    }
    if (i < 0) break;
    printf("NO");
    return 0;
  }
  printf("YES\n");
}
