#include <bits/stdc++.h>
using namespace std;
int prime[1000];
int len_p;
void get_prime() {
  len_p = 2;
  prime[0] = 2;
  prime[1] = 3;
  int j, n, i;
  for (n = 5; n <= 2000; n += 2) {
    int k = sqrt(n);
    for (j = 0; prime[j] <= k && n % prime[j]; j++)
      ;
    if (prime[j] > k) {
      prime[len_p++] = n;
    }
  }
}
char str[1050];
int num[200];
char ou[1050];
int main() {
  get_prime();
  scanf("%s", str);
  int l = strlen(str);
  int t = l / 2;
  int i;
  memset(num, 0, sizeof(num));
  for (i = 0; str[i]; i++) num[str[i]]++;
  for (i = 0; i < len_p; i++) {
    if (prime[i] > t) {
      break;
    }
  }
  int icount, j;
  for (icount = 1; prime[i] <= l; ++i, icount++)
    ;
  int Max = 0;
  int Max_ch = 0;
  for (i = 'a'; i <= 'z'; i++) {
    if (Max < num[i]) {
      Max_ch = i;
      Max = num[i];
    }
  }
  memset(ou, 0, sizeof(ou));
  if (Max >= l - icount) {
    for (i = 0; prime[i] <= l / 2; i++) {
      for (j = prime[i]; j <= l; j += prime[i]) {
        if (ou[j - 1] == 0) {
          ou[j - 1] = Max_ch;
          num[Max_ch]--;
        }
      }
    }
    for (i = 'a'; i <= 'z'; i++) {
      if (num[i]) {
        for (j = 0; j < l && num[i]; j++) {
          if (ou[j] == 0) {
            ou[j] = i;
            num[i]--;
          }
        }
      }
    }
    ou[l] = 0;
    printf("YES\n");
    puts(ou);
  } else {
    puts("NO");
  }
}
