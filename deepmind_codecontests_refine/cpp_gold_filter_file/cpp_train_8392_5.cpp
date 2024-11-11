#include <bits/stdc++.h>
using namespace std;
char st[400005];
char even[400005], odd[800005];
int ptr[2][2], c[1005];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", st);
  for (int i = 0; i < n; i++) c[st[i]]++;
  for (int i = 0; i < 1000; i++) {
    if (c[i] == 0) continue;
    if (c[i] % 2 == 0) {
      for (int j = c[i] / 2; j > 0; j--) even[ptr[0][1]++] = i;
    } else {
      for (int j = c[i] / 2; j > 0; j--) even[ptr[0][1]++] = i;
      odd[ptr[1][1]++] = i;
    }
  }
  if (ptr[1][1] > ptr[0][1]) {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%c ", st[i]);
    return 0;
  }
  if (ptr[1][1] == 0 || ptr[1][1] == 1) {
    printf("1\n");
    for (int i = ptr[0][0]; i < ptr[0][1]; i++) printf("%c", even[i]);
    if (ptr[1][1] == 1) printf("%c", odd[0]);
    for (int i = ptr[0][1] - 1; i >= ptr[0][0]; i--) printf("%c", even[i]);
    return 0;
  }
  while (1) {
    if (ptr[1][1] - ptr[1][0] > ptr[0][1] - ptr[0][0]) {
      printf("%d\n", n);
      for (int i = 0; i < n; i++) printf("%c ", st[i]);
      return 0;
    } else if ((ptr[0][1] - ptr[0][0]) % (ptr[1][1] - ptr[1][0]) == 0) {
      printf("%d\n", (ptr[1][1] - ptr[1][0]));
      int t = (ptr[1][1] - ptr[1][0]);
      int tt = (ptr[0][1] - ptr[0][0]) / t;
      for (int i = 1; i <= t; i++) {
        for (int j = ptr[0][0]; j < ptr[0][0] + tt; j++) printf("%c", even[j]);
        printf("%c", odd[ptr[1][0]]);
        for (int j = ptr[0][0] + tt - 1; j >= ptr[0][0]; j--)
          printf("%c", even[j]);
        ptr[1][0]++;
        ptr[0][0] += tt;
        printf(" ");
      }
      return 0;
    }
    odd[ptr[1][1]++] = even[ptr[0][0]];
    odd[ptr[1][1]++] = even[ptr[0][0]++];
  }
}
