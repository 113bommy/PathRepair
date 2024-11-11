#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main() {
  int n;
  int flag = 0;
  scanf("%d", &n);
  scanf("%s", s + 1);
  int pos = 0;
  int sum = 0;
  int MIN = 1e9;
  for (int i = 1; i <= n; i++) {
    if (pos == 0 && s[i] != 'B') sum++;
    if (pos == 1 && s[i] != 'R') sum++;
    if (pos == 2 && s[i] != 'G') sum++;
    pos++;
    pos = pos % 3;
  }
  if (sum < MIN) flag = 1, MIN = sum;
  pos = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (pos == 0 && s[i] != 'B') sum++;
    if (pos == 1 && s[i] != 'G') sum++;
    if (pos == 2 && s[i] != 'R') sum++;
    pos++;
    pos = pos % 3;
  }
  if (sum < MIN) flag = 2, MIN = sum;
  pos = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (pos == 0 && s[i] != 'R') sum++;
    if (pos == 1 && s[i] != 'B') sum++;
    if (pos == 2 && s[i] != 'G') sum++;
    pos++;
    pos = pos % 3;
  }
  if (sum < MIN) flag = 3, MIN = sum;
  pos = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (pos == 0 && s[i] != 'R') sum++;
    if (pos == 1 && s[i] != 'G') sum++;
    if (pos == 2 && s[i] != 'B') sum++;
    pos++;
    pos = pos % 3;
  }
  if (sum < MIN) flag = 4, MIN = sum;
  pos = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (pos == 0 && s[i] != 'G') sum++;
    if (pos == 1 && s[i] != 'R') sum++;
    if (pos == 2 && s[i] != 'B') sum++;
    pos++;
    pos = pos % 3;
  }
  if (sum < MIN) flag = 5, MIN = sum;
  pos = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (pos == 0 && s[i] != 'G') sum++;
    if (pos == 1 && s[i] != 'B') sum++;
    if (pos == 2 && s[i] != 'R') sum++;
    pos++;
    pos = pos % 3;
  }
  if (sum < MIN) flag = 6, MIN = sum;
  char a, b, c;
  if (flag == 1) a = 'B', b = 'R', c = 'G';
  if (flag == 2) a = 'B', b = 'G', c = 'R';
  if (flag == 3) a = 'R', b = 'B', c = 'G';
  if (flag == 4) a = 'R', b = 'G', c = 'B';
  if (flag == 5) a = 'G', b = 'R', c = 'B';
  if (flag == 6) a = 'G', b = 'B', c = 'R';
  pos = 0;
  printf("%d\n", MIN);
  for (int i = 1; i <= n; i++) {
    if (pos == 0) printf("%c", a);
    if (pos == 1) printf("%c", b);
    if (pos == 2) printf("%c", c);
    pos++;
    pos = pos % 3;
  }
  printf("\n");
}
