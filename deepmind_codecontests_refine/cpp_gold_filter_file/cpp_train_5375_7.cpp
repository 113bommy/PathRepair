#include <bits/stdc++.h>
using namespace std;
int euc(int a, int b) {
  if (a < b) {
    int t = a;
    a = b;
    b = t;
  }
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int nsd = euc(a, b);
  long long int lcm = ((long long int)a) * ((long long int)b) / nsd;
  int scoreA = (int)((long long int)(lcm / a)) - 1;
  int scoreB = (int)((long long int)(lcm / b)) - 1;
  if (a > b)
    scoreA++;
  else
    scoreB++;
  if (scoreA > scoreB)
    printf("Dasha");
  else if (scoreA == scoreB)
    printf("Equal");
  else {
    printf("Masha");
  }
  return 0;
}
