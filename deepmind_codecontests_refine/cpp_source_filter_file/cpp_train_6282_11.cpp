#include <bits/stdc++.h>
using namespace std;
int gInt() {
  int i;
  scanf("%d", &i);
  return i;
}
long long int gLong() {
  long long int i;
  scanf("%lld", &i);
  return i;
}
double gDouble() {
  double i;
  scanf("%lf", &i);
  return i;
}
void quit() {
  fflush(stdout);
  exit(0);
}
int main(int argc, char** argv) {
  int dega = gInt(), degb = gInt();
  int majA = gInt();
  for (int count = 0; count < dega; count++) gInt();
  int majB = gInt();
  for (int count = 0; count < degb; count++) gInt();
  if (dega == degb) {
    for (int count = 2; count < 101; count++) {
      if (majA % count == 0 && majB % count == 0) {
        majA /= count;
        majB /= count;
      }
    }
    if ((majA > 0 && majB < 0) || (majA < 0 && majB < 0)) {
      majA *= -1;
      majB *= -1;
    }
    printf("%d/%d\n", majA, majB);
  } else if (dega > degb) {
    if (majA * majB > 0)
      printf("Infinity\n");
    else
      printf("-Infinity\n");
  } else
    printf("0/1\n");
  quit();
}
