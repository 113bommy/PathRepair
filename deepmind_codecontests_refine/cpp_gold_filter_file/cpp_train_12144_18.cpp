#include <bits/stdc++.h>
using namespace std;
const int maxL = 5010;
char s[maxL * 2];
int record[26][26][maxL], l, result = 0;
int i, j, k;
int main() {
  cin >> s;
  l = strlen(s);
  for (i = 0; i < l; i++) {
    s[i + l] = s[i];
  }
  memset(record, 0, sizeof(record));
  for (i = 0; i < l; i++) {
    for (j = i + 1; j < i + l; j++) {
      record[s[i] - 'a'][s[j] - 'a'][j - i]++;
    }
  }
  for (i = 0; i < 26; i++) {
    int temp = 0;
    for (j = 0; j < l; j++) {
      int sum = 0;
      for (k = 0; k < 26; k++) {
        if (record[i][k][j] == 1) {
          sum++;
        }
      }
      temp = max(sum, temp);
    }
    result += temp;
  }
  printf("%.14f\n", double(result) / l);
  return 0;
}
