#include <bits/stdc++.h>
using namespace std;
void answer();
int main() {
  int q;
  scanf("%d", &q);
  while (q--) answer();
  return 0;
}
void answer() {
  string pswd;
  cin >> pswd;
  int check[26] = {};
  char output[1000] = {};
  int i = 1, it = 26, flag = 0, minit = 26;
  output[26] = pswd[0];
  check[(pswd[0] - 'a')] = 1;
  while (pswd[i] != 0) {
    if (pswd[i] == output[it + 1])
      it++;
    else if (pswd[i] == output[it - 1])
      it--;
    else if ((check[pswd[i] - 'a']) == 1) {
      flag = 1;
      break;
    } else {
      if (output[it + 1] == 0) {
        check[pswd[i] - 'a'] = 1;
        output[it + 1] = pswd[i];
        it++;
      } else if (output[it - 1] == 0) {
        check[pswd[i] - 'a'] = 1;
        output[it - 1] = pswd[i];
        it--;
      } else {
        flag = 1;
        break;
      }
    }
    i++;
    minit = min(minit, it);
  }
  if (flag == 1) {
    printf("NO\n");
  } else {
    printf("YES\n");
    i = minit;
    for (; output[i] != 0; i++) {
      printf("%c", output[i]);
    }
    for (i = 0; i < 26; i++) {
      if (check[i] == 0) {
        printf("%c", char(i + 'a'));
      }
    }
    printf("\n");
  }
}
