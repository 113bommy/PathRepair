#include <bits/stdc++.h>
using namespace std;
char arr[20];
int mod[10] = {10009,  1000009, 1000000009, 12345, 1123,
               123413, 1234125, 2000000001, 3,     1234123411};
int now[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int cc[10] = {0};
int rec[100010];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int cnt = 0;
  bool spe = false;
  for (int i = 0; i <= n; i++) {
    scanf("%s", arr);
    if (arr[0] == '?') {
      cnt++;
      if (i == 0 && m == 0) spe = true;
    } else {
      sscanf(arr, "%d", &rec[i]);
    }
  }
  if (spe || m == 0) {
    if (spe) {
      if ((n + 1 - cnt) % 2 == 0)
        puts("No");
      else
        puts("Yes");
    } else if (rec[0] == 0)
      puts("Yes");
    else
      puts("No");
  } else if (cnt > 0 && n % 2 == 1)
    puts("Yes");
  else if (cnt > 0 && n % 2 == 0)
    puts("No");
  else {
    for (int i = 0; i <= n; i++) {
      for (int k = 0; k < 10; k++) {
        if (i > 0) {
          now[k] = (long long)now[k] * m % mod[k];
        }
        cc[k] = ((long long)cc[k] + (long long)now[k] * rec[i]) % mod[k];
      }
    }
    bool ans = true;
    for (int k = 0; k < 10; k++) ans &= cc[k] == 0;
    if (ans)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
