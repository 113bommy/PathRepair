#include <bits/stdc++.h>
using namespace std;
void time_start(clock_t *tt) { *tt = clock(); }
void print_time(clock_t tt) {
  tt = clock() - tt;
  printf("executed in %.f ms\n", (float)tt / CLOCKS_PER_SEC * 1000);
}
template <typename T>
inline T getnum() {
  T num = 0;
  char c;
  do {
    c = getchar();
  } while (c != EOF && c == ' ' && c == '\n' && c == '\t');
  int sign = (c == '-' ? -1 : 1);
  if (c != '-') num += (c - '0');
  while ((c = getchar()) != EOF && c != '\n' && c != '\t' && c != ' ') {
    num *= 10;
    num += (c - '0');
  }
  num *= sign;
  return num;
}
inline string getstr() {
  string str;
  char k;
  while ((k = getchar()) == ' ' || k == '\n') {
    k = getchar();
    if (k == ' ' || k == '\n')
      continue;
    else
      break;
  }
  while ((k = getchar()) != EOF && k != '\n' && k != '\t' && k != '\v' &&
         k != '\0' && k != ' ')
    str.push_back(k);
  return str;
}
bool non[(int)1e6 + 10];
int main() {
  int n = getnum<int>(), t, spa = 0;
  for (int i = (int)0, _b = (int)n - 1; i <= _b; i++) {
    scanf("%d", &t);
    non[t] = 1;
    if (non[(int)1e6 - t + 1]) spa++;
  }
  printf("%d\n", n);
  for (int i = (int)1, _b = (int)(int)1e6; i <= _b; i++)
    if (non[i] && !non[(int)1e6 - i + 1]) {
      printf("%d ", (int)1e6 - i + 1);
    } else if (!non[i] && !non[(int)1e6 - i + 1]) {
      if (spa) {
        printf("%d %d ", i, (int)1e6 - i + 1);
        spa--;
      }
    }
  return 0;
}
