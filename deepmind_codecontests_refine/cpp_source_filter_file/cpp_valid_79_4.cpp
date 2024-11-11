#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n;
char s[N];
inline bool isprime(int num) {
  if (num <= 1) return 0;
  for (int i = 1; i <= sqrt(num); i++)
    if (num % i == 0) return 0;
  return 1;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    bool succeed = 0;
    for (int i = 1; i <= n; i++)
      if (s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7') {
        puts("1");
        printf("%c\n", s[i]);
        succeed = 1;
        break;
      }
    if (succeed) continue;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        if (succeed) break;
        int num = (s[i] - '0') * 10 + (s[j] - '0');
        if (!isprime(num)) {
          puts("2");
          printf("%c%c\n", s[i], s[j]);
          succeed = 1;
          break;
        }
      }
    if (!succeed) assert(0);
  }
  return 0;
}
