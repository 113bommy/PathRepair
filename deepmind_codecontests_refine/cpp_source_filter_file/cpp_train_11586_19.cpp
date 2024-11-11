#include <bits/stdc++.h>
using namespace std;
char str[105][105];
int n, m, k;
int gwin, rwin;
vector<int> num;
int dp[105];
void get() {
  gwin = -1;
  rwin = -1;
  for (int i = 1; i <= n; i++) {
    int R = -1;
    int G = -1;
    int has = 0;
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'G')
        G = j;
      else if (str[i][j] == 'R')
        R = j;
      else if (str[i][j] == '-')
        has = 1;
    }
    if (G != -1 && R == -1 && has) gwin = 1;
    if (R != -1 && G == -1 && has) rwin = 1;
    if (R != -1 && G != -1 && abs(G - R) != 1) num.push_back(abs(R - G));
  }
}
void Compute() {
  if (rwin == 1 && gwin == -1) {
    printf("Second\n");
  } else if (rwin == -1 && gwin == 1) {
    printf("First\n");
  } else if (rwin == 1 && gwin == 1)
    printf("Draw\n");
  else {
    bool flag = true;
    for (int bit = 0; bit <= 8; bit++) {
      int sum = 0;
      for (size_t i = 0; i < num.size(); i++) {
        int v = num[i];
        sum = sum + ((v >> bit) & 1);
      }
      if (sum % (k + 1)) {
        flag = false;
        break;
      }
    }
    if (!flag)
      printf("First\n");
    else
      printf("Second\n");
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str[i]);
  }
  get();
  Compute();
  return 0;
}
