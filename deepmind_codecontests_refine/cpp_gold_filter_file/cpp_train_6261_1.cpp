#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500025;
char str[MAX_N], mo[MAX_N];
int Next[MAX_N], n2;
void GetNext() {
  int i = 0, j = -1;
  while (i < n2) {
    if (j == -1 || mo[i] == mo[j]) {
      ++i, ++j, Next[i] = j;
    } else
      j = Next[j];
  }
  return;
}
int main() {
  int num = 0, num_ = 0, NUM = 0, NUM_ = 0;
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    if (str[i] == '1')
      num++;
    else
      num_++;
  }
  scanf("%s", mo);
  n2 = strlen(mo);
  for (int i = 0; i < n2; i++) {
    if (mo[i] == '1')
      NUM++;
    else
      NUM_++;
  }
  Next[0] = -1;
  GetNext();
  if (num >= NUM && num_ >= NUM_) {
    printf("%s", mo);
    num -= NUM;
    num_ -= NUM_;
    while (num && num_) {
      for (int i = Next[n2]; i < n2; i++) {
        if (mo[i] == '1')
          num--;
        else
          num_--;
        printf("%c", mo[i]);
        if (!num && NUM || !num_ && NUM_) break;
      }
    }
    while (num) {
      printf("1");
      num--;
    }
    while (num_) {
      printf("0");
      num_--;
    }
    printf("\n");
  } else {
    printf("%s\n", str);
  }
  return 0;
}
