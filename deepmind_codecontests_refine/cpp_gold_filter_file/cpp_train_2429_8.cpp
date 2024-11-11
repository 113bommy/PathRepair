#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, len, countbig = 0, countles = 0;
  char str[400];
  scanf("%d", &len);
  scanf("%s", &str);
  sort(str, str + len);
  sort(str + len, str + len * 2);
  for (int i = 0; i < len; i++) {
    if (str[i] < str[i + len]) {
      countles++;
    }
    if (str[i] > str[i + len]) {
      countbig++;
    }
  }
  if (countles == len || countbig == len) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
