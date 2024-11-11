#include <bits/stdc++.h>
using namespace std;
int t, n, fr[8000005], str[8000005][2], ar[8000005];
int main() {
  memset(str, -1, sizeof(str));
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    ar[i] = x;
    fr[x]++;
  }
  for (int i = 0; i <= 4200004; i++) {
    if (i & 1) {
      if (fr[i ^ 1]) str[i][0] = i ^ 1;
    } else {
      if (fr[i])
        str[i][0] = i;
      else if (fr[i | 1])
        str[i][0] = (i | 1);
    }
  }
  for (int j = 1; j <= 24; j++) {
    for (int i = 0; i <= 4200026; i++) {
      if (i & (1 << j)) {
        str[i][j] = -1;
        if (str[i ^ (1 << j)][(j - 1) % 2] != -1) {
          str[i][j % 2] = str[i ^ (1 << j)][(j - 1) % 2];
        }
      } else {
        str[i][j] = -1;
        if (str[i][(j - 1) % 2] != -1)
          str[i][j % 2] = str[i][(j - 1) % 2];
        else if ((i | (1 << j)) <= 4200026 &&
                 str[i | (1 << j)][(j - 1) % 2] != -1) {
          str[i][j % 2] = str[i | (1 << j)][(j - 1) % 2];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << str[ar[i]][24 % 2] << " ";
    if (str[ar[i]][0] != -1 && (str[ar[i]][0] & ar[i]))
      while (1)
        ;
  }
}
