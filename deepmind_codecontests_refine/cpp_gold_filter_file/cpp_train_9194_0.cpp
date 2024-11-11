#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const double PI = acos(-1.0);
int main() {
  int t;
  cin >> t;
  char str[200];
  int M = 1000000007;
  int D[101][2501] = {0};
  for (int i = (0), ei = (26); i < ei; i++) D[0][i] = 1;
  for (int i = (1), ei = (101); i < ei; i++)
    for (int s = (0), es = (2501); s < es; s++)
      for (int j = (0), ej = (26); j < ej; j++)
        if (s - j >= 0) D[i][s] = (D[i][s] + D[i - 1][s - j]) % M;
  for (int test = (0), etest = (t); test < etest; test++) {
    scanf(" %s", str);
    int sum = 0;
    int n = strlen(str);
    for (int i = (0), ei = (n); i < ei; i++) sum += str[i] - 'a';
    printf("%d\n", (D[n - 1][sum] - 1 + M) % M);
  }
  return 0;
}
