#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, count = 0, arr[110] = {0}, arry[110] = {0};
  char s1[110], s2[110], s3[110];
  cin >> s1;
  cin >> s2;
  cin >> s3;
  for (i = 0; i < strlen(s1); i++) {
    for (j = 0; j < strlen(s3); j++) {
      if (s3[j] == s1[i]) {
        s3[j] = ' ';
        arr[i]++;
        break;
      }
    }
  }
  for (i = 0; i < strlen(s2); i++) {
    for (j = 0; j < strlen(s3); j++) {
      if (s3[j] == s2[i]) {
        s3[j] = ' ';
        arry[i]++;
        break;
      }
    }
  }
  for (i = 0; i < strlen(s1); i++) {
    if (arr[i] == 0) count++;
  }
  for (i = 0; i < strlen(s2); i++) {
    if (arry[i] == 0) count++;
  }
  for (j = 0; j < strlen(s3); j++) {
    if (s3[j] != ' ') {
      count++;
      break;
    }
  }
  if (count == 0)
    cout << "YES";
  else
    cout << "NO";
}
