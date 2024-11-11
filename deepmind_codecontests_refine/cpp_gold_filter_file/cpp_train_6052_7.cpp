#include <bits/stdc++.h>
using namespace std;
int N, M, K;
long long a, b, c;
char inp[300005];
int main() {
  scanf("%s", inp + 1);
  int ystate = 1;
  int xstate = 0;
  for (int i = 1; inp[i]; i++) {
    if (inp[i] == '0') {
      printf("%d 1\n", ystate);
      ystate ^= 2;
    } else {
      printf("%d 3\n", xstate + 1);
      xstate++;
      xstate %= 4;
    }
  }
}
