#include <bits/stdc++.h>
using namespace std;
int n, m;
double ans = 0;
char s[5009];
int b[30][30][5009];
int c[30];
int main() {
  cin >> s;
  n = strlen(s);
  for (int i = n; i < 2 * n; i++) {
    s[i] = s[i - n];
    c[s[i] - 97]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j - i < n; j++) {
      b[int(s[i]) - 97][int(s[j]) - 97][j - i]++;
    }
  }
  for (int i = 0; i < 26; i++) {
    int tmp = 0;
    for (int j = 1; j < n; j++) {
      int sum = 0;
      for (int k = 0; k < 26; k++) {
        if (b[i][k][j] == 1) sum++;
      }
      tmp = max(sum, tmp);
    }
    ans += tmp;
  }
  ans = ans / n;
  printf("%.10lf", ans);
}
