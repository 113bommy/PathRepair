#include <bits/stdc++.h>
const int START = 300;
const int END = 1439;
int a, tA, b, tB, hh, mm;
int main() {
  scanf("%d%d", &a, &tA);
  scanf("%d%d", &b, &tB);
  scanf("%d:%d", &hh, &mm);
  int tS = hh * 60 + mm, answer = 0;
  for (int i = 1; START + (i - 1) * b <= END; i++) {
    if (START + (i - 1) * b >= tS + tA) break;
    if (START + (i - 1) * b + tB <= tS) continue;
    answer++;
  }
  printf("%d\n", answer);
  return 0;
}
