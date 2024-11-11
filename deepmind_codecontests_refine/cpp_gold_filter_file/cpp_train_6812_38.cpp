#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
bool dp[100][100][1000];
bool W[100][100][1000];
int main() {
  int N;
  int M;
  int K;
  scanf("%d %d %d", &N, &M, &K);
  K++;
  char ch[101];
  for (int n = 0; n < N; n++) {
    scanf("%s", ch);
    for (int m = 0; m < M; m++) {
      arr[n][m] = ch[m] - '0';
    }
  }
  memset(dp, false, sizeof(dp));
  for (int m = 0; m < M; m++) {
    dp[N - 1][m][arr[N - 1][m]] = true;
  }
  for (int n = N - 2; n >= 0; n--) {
    for (int m = 0; m < M; m++) {
      int y[] = {n + 1, n + 1};
      int x[] = {m - 1, m + 1};
      for (int pos = 0; pos < 2; pos++) {
        int Y = y[pos];
        int X = x[pos];
        if (Y >= 0 && Y < N && X >= 0 && X < M) {
          for (int k = 0; k < 1000; k++) {
            if (dp[Y][X][k]) {
              dp[n][m][k + arr[n][m]] = true;
              W[n][m][k + arr[n][m]] = pos;
            }
          }
        }
      }
    }
  }
  int sol = -1;
  int pos = -1;
  for (int k = 0; k < 1000; k += K) {
    for (int m = 0; m < M; m++) {
      if (dp[0][m][k]) {
        sol = k;
        pos = m;
      }
    }
  }
  printf("%d\n", sol);
  if (sol != -1) {
    int help = sol;
    stack<int> st;
    for (int n = 0; n < N - 1; n++) {
      st.push(W[n][pos][help]);
      if (W[n][pos][help] == 0) {
        help -= arr[n][pos];
        pos--;
      } else {
        help -= arr[n][pos];
        pos++;
      }
    }
    printf("%d\n", pos + 1);
    while (!st.empty()) {
      if (st.top() == 0) {
        printf("R");
      } else {
        printf("L");
      }
      st.pop();
    }
    printf("\n");
  }
  return 0;
}
