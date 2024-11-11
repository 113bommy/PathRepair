#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  char ch[10001];
  scanf("%s", ch);
  int a[10000] = {0};
  int prime[1000];
  int count = 0;
  for (int i = 2; i < 1001; i++) {
    if (a[i] == 0) {
      prime[count++] = i;
      for (int j = i * i; j > 0 && j < 1001; j += i) a[j] = 1;
    }
  }
  int len = strlen(ch);
  if (len <= 3)
    printf("%s\n", ch);
  else {
    int val;
    for (int i = 0; i < count; i++) {
      if (prime[i] * 2 > len) {
        val = prime[i - 1];
        break;
      }
    }
    int ans[10001] = {0}, temp = 1, c = 0;
    for (int i = 0; prime[i] <= val; i++) {
      for (int j = prime[i]; j <= len; j += prime[i]) ans[j] = temp;
    }
    for (int i = 1; i <= len; i++)
      if (ans[i] == temp) {
        c++;
      }
    int check[26] = {0};
    for (int i = 0; ch[i] != '\0'; i++) check[ch[i] - 'a']++;
    char answer[10001] = {'\0'};
    int flag = 0;
    for (int i = 0; i < 26; i++)
      if (check[i] >= c) {
        val = i;
        flag = 1;
        break;
      }
    if (flag == 0)
      printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 1; i <= len; i++) {
        if (ans[i] == 1) {
          answer[i - 1] = val + 'a';
          check[val]--;
        }
      }
      for (int i = 1; i <= len; i++) {
        if (ans[i] != 1) {
          for (int j = 0; j < 26; j++) {
            if (check[j] > 0) {
              answer[i - 1] = j + 'a';
              check[j]--;
              break;
            }
          }
        }
      }
      answer[len] = '\0';
      printf("%s\n", answer);
    }
  }
  return 0;
}
