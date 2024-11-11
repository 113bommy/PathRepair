#include <bits/stdc++.h>
const int N = 5000 + 10;
char string[N];
int sg[N], visit[N], n, length;
bool check(int x) {
  char c = string[x];
  string[x] = '#';
  int result = 0;
  for (int i = 2; i + 1 <= length;) {
    if (string[i - 1] == string[i + 1] && i != x) {
      int j = i;
      while (j + 1 <= length && j != x && string[j - 1] == string[j + 1]) {
        j++;
      }
      result ^= sg[j - i];
      i = j;
    } else {
      i++;
    }
  }
  string[x] = c;
  return result == 0;
}
int main() {
  sg[0] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      visit[sg[std::max(j - 2, 0)] ^ sg[std::max(i - j - 1, 0)]] = i;
    }
    sg[i] = 0;
    while (visit[sg[i]] == i) {
      sg[i]++;
    }
  }
  scanf("%s", string + 1);
  length = strlen(string + 1);
  int answer = -1;
  for (int i = 2; i < length; ++i) {
    if (string[i - 1] == string[i + 1] && check(i)) {
      answer = i;
      break;
    }
  }
  if (answer == -1) {
    puts("Second");
  } else {
    printf("First\n%d\n", answer);
  }
  return 0;
}
