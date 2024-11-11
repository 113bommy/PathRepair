#include <bits/stdc++.h>
using namespace std;
char s[100005];
int let[26];
long long int fast_pow(int base, int p) {
  if (p == 0) {
    return 1;
  }
  long long int a = fast_pow(base, p / 2);
  if (p % 2) {
    return (((a * a) % ((int)(10e9 + 7))) * base) % ((int)(10e9 + 7));
  } else {
    return (a * a) % ((int)(10e9 + 7));
  }
}
int main(void) {
  int n;
  int big = 0;
  int base = 0;
  scanf(" %d", &n);
  scanf(" %s", s);
  memset(let, 0, sizeof(let));
  for (int i = 0; s[i] != '\0'; i++) {
    let[s[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (let[i] == big) {
      base++;
    } else if (let[i] > big) {
      base = 1;
      big = let[i];
    }
  }
  printf("%lld\n", fast_pow(base, n));
  return 0;
}
