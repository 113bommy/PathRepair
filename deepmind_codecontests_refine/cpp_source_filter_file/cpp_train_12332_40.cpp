#include <bits/stdc++.h>
using namespace std;
string output[6] = {" ", "S", "M", "L", "XL", "XXL"};
int main() {
  int s[20] = {0};
  while (scanf("%d%d%d%d%d", &s[1], &s[2], &s[3], &s[4], &s[5]) != EOF) {
    int i, j, k;
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
      int number;
      string size;
      cin >> size;
      for (j = 1; j <= 5; j++) {
        if (size == output[j]) {
          number = j;
          break;
        }
      }
      for (j = 0; j <= 2; j++) {
        if ((number + j <= 5) && (s[number + j] > 0)) {
          s[number + j]--;
          cout << output[number + j] << endl;
          break;
        }
        if ((number - j) >= 1 && (s[number - j] > 0)) {
          s[number - j]--;
          cout << output[number - j] << endl;
          break;
        }
      }
    }
    memset(s, 0, sizeof(s));
  }
  return 0;
}
