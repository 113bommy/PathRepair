#include <bits/stdc++.h>
int main() {
  int d, n;
  scanf("%d", &n);
  int dp[7];
  char str[4];
  for (int i = 0; i < 7; i++) {
    dp[i] = 1000000;
  }
  while (n--) {
    scanf("%d%s", &d, str);
    if (!strcmp(str, "A")) {
      if (dp[0] > d) {
        dp[0] = d;
      }
    } else if (!strcmp(str, "B")) {
      if (dp[1] > d) {
        dp[1] = d;
      }
    } else if (!strcmp(str, "C")) {
      if (dp[2] > d) {
        dp[2] = d;
      }
    } else if (!strcmp(str, "AB") || !strcmp(str, "BA")) {
      if (dp[3] > d) {
        dp[3] = d;
      }
    } else if (!strcmp(str, "BC") || !strcmp(str, "CB")) {
      if (dp[4] > d) {
        dp[4] = d;
      }
    } else if (!strcmp(str, "AC") || !strcmp(str, "CA")) {
      if (dp[5] > d) {
        dp[5] = d;
      }
    } else if (!strcmp(str, "ABC") || !strcmp(str, "ACB") ||
               !strcmp(str, "BAC") || !strcmp(str, "BCA") ||
               !strcmp(str, "CAB") || !strcmp(str, "CBA")) {
      if (dp[6] > d) {
        dp[6] = d;
      }
    } else {
      printf("GHOTALA\n");
    }
  }
  int min = dp[6];
  int term = dp[0] + dp[1] + dp[2];
  if (term < min) {
    min = term;
  }
  term = dp[0] + dp[4];
  if (term < min) {
    min = term;
  }
  term = dp[1] + dp[5];
  if (term < min) {
    min = term;
  }
  term = dp[2] + dp[3];
  if (term < min) {
    min = term;
  }
  term = dp[3] + dp[4];
  if (term < min) {
    min = term;
  }
  term = dp[3] + dp[5];
  if (term < min) {
    min = term;
  }
  term = dp[4] + dp[5];
  if (term < min) {
    min = term;
  }
  if (min == 100001) {
    printf("%d\n", -1);
  } else {
    printf("%d\n", min);
  }
}
