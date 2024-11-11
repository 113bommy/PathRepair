#include <bits/stdc++.h>
using namespace std;
int n;
int state[15];
void init() { scanf("%d", &n); }
void process() {
  while (n--) {
    char ins[5];
    int val;
    scanf("%s%d", ins, &val);
    if (ins[0] == '&') {
      for (int i = 0; i < 10; i++) {
        if ((val & (1 << i)) == 0) state[i] = 1;
      }
    } else if (ins[0] == '|') {
      for (int i = 0; i < 10; i++) {
        if ((val & (1 << i)) == 1) state[i] = 2;
      }
    } else if (ins[0] == '^') {
      for (int i = 0; i < 10; i++) {
        if ((val & (1 << i)) == 1) state[i] = 3 - state[i];
      }
    }
  }
  printf("3\n");
  {
    int tmp = 0;
    for (int i = 0; i < 10; i++) {
      if (state[i] != 1) tmp += (1 << i);
    }
    printf("& %d\n", tmp);
  }
  {
    int tmp = 0;
    for (int i = 0; i < 10; i++) {
      if (state[i] == 2) tmp += (1 << i);
    }
    printf("| %d\n", tmp);
  }
  {
    int tmp = 0;
    for (int i = 0; i < 10; i++) {
      if (state[i] == 3) tmp += (1 << i);
    }
    printf("^ %d\n", tmp);
  }
}
int main() {
  init();
  process();
  return 0;
}
